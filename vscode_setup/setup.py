import os
import json

def clear(os_name):
    if os_name == 'nt':
        os.system('cls')
    else:
        os.system('clear')

def exit(reason):
    print(reason)
    input("press enter to exit.")

def append_slash_to_end_if_not_exist(path):
    path = path.replace("\\", "/")
    if path[-1] != "/":
        path += "/"
    return path

def find_arduino_path(os_name):
    if os_name == "nt": # windows
        local_appdata_path = os.getenv('LOCALAPPDATA')
        arduino_path = local_appdata_path + "\Arduino15"
    if os_name == "posix": # unix systems (linux, macos)
        user_home = os.getenv('HOME')
        arduino_path = user_home + "/.arduino15"
    if os.path.exists(arduino_path):
        return append_slash_to_end_if_not_exist(arduino_path)
    arduino_path = input("the script cannot find the arduino path, please enter the .arduino15 path manually\nhttps://support.arduino.cc/hc/en-us/articles/360018448279-Open-the-Arduino15-folder:\n")
    if not os.path.exists(arduino_path):
        exit("invaild path")
    clear(os_name)
    return append_slash_to_end_if_not_exist(arduino_path)

script_dir = append_slash_to_end_if_not_exist(os.path.dirname( __file__ ))
base_dir = append_slash_to_end_if_not_exist(os.path.abspath(os.path.join(script_dir, '..')))

def patch_json(os_name):
    json_file = None
    arduino_path = find_arduino_path(os_name)
    if os_name == "nt": # windows
        json_file = script_dir + "templates/windows.json"
    if os_name == "posix": # unix systems (linux, macos)
        json_file = script_dir + "templates/unix.json"
    json_file = json.load(open(json_file, "r"))
    configs = json_file["configurations"][0]

    configs["compilerPath"] = arduino_path + configs["compilerPath"]
    for path in range(len(configs["includePath"])):
        configs["includePath"][path] = arduino_path + configs["includePath"][path]
    configs["includePath"].insert(0, base_dir)
    for path in range(len(configs["forcedInclude"])):
        configs["forcedInclude"][path] = arduino_path + configs["forcedInclude"][path]

    return json_file

os_name = os.name
clear(os_name)
json_file = patch_json(os_name)

os.makedirs(base_dir + ".vscode/", exist_ok=True)
json.dump(json_file, open(base_dir + ".vscode/c_cpp_properties.json", 'w'), indent=4)
open(base_dir + ".vscode/settings.json", 'w').write(open(script_dir +"templates/settings.json", "r").read())
open(base_dir + ".vscode/arduino.json", 'w').write(open(script_dir +"templates/arduino.json", "r").read())