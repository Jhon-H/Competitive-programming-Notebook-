import sys

def create_files(name, base_file):
  # Leer el código base desde el archivo
  with open(base_file, 'r') as f:
    code = f.read()

  # Crear archivo CPP
  cpp_filename = f'{name}.cpp'
  with open(cpp_filename, 'w') as cpp_file:
    cpp_file.write(code)

  # Crear archivo de entrada
  in_filename = f'{name}.in'
  with open(in_filename, 'w'):
    pass

  # Crear archivo de salida
  out_filename = f'{name}.out'
  with open(out_filename, 'w'):
    pass


if __name__ == '__main__':
  if len(sys.argv) < 2:
    print("[ERROR] Debe proporcionar un nombre de archivo como argumento.")
    sys.exit(1)

  name = sys.argv[1]
  create_files(name, ".\scripts\\base.cpp")