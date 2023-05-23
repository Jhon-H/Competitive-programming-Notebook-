import subprocess
import sys

def compile_and_execute(name):
  compile_command = f'g++ .\\{name}.cpp -o a'
  execute_command = f'type .\\{name}.in | .\\a.exe > .\\{name}.out'

  subprocess.run(compile_command, shell=True, check=True)
  subprocess.run(execute_command, shell=True, check=True)

if __name__ == '__main__':
  if len(sys.argv) < 2:
    print("[ERROR] Debe proporcionar un nombre de archivo como argumento.")
    sys.exit(1)

  name = sys.argv[1]
  compile_and_execute(name)
