import ast

# Refer to Documentations/python_code_that_learns.py for more explanation
# Define the source code to parse
source_code = '''
def add_numbers(x, y):
    result = x + y
    return result

a = 5
b = 10
c = add_numbers(a, b)
'''

# Parse the source code and generate an AST
tree = ast.parse(source_code)

# Extract variable and function names
variables = []
functions = []
for node in ast.walk(tree):
    if isinstance(node, ast.Name):
        variables.append(node.id)
    elif isinstance(node, ast.FunctionDef):
        functions.append(node.name)

# Print the extracted names
print('Variables:', variables)
print('Functions:', functions)


# OUTPUT:
#   Variables: ['a', 'b', 'c']
#   Functions: ['add_numbers']
