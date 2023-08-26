
name = input("Enter the name of the document: ")
n = int(input("Enter the number of documents you want: "))
docs = []
for i in range(n):
    doc = input(f"Enter {name}_{i+1}: ")
    docs.append(doc)
print("Documents:", docs)

matrix = {}
norep = set()
for doc in docs:
    for term in doc.split():
        norep.add(term)
for term in norep:
    matrix[term] = []
    for doc in docs:
        if term in doc:
            matrix[term].append(1)
        else:
            matrix[term].append(0)

print("Term-Document Matrix:")
for term, doc_vector in matrix.items():
    print(term, doc_vector)

def logical_and(v1, v2):
    return [a & b for a, b in zip(v1, v2)]

def logical_or(v1, v2):
    return [a | b for a, b in zip(v1, v2)]

def logical_not(v):
    return [0 if val == 1 else 1 for val in v]


#query evaluation

precedence = {'NOT': 3, 'AND': 2, 'OR': 1}
n1 = int(input("Enter the number of words to check: "))
words = []
for i in range(n1):
    word = input(f"Enter word_{i+1}: ")
    words.append(word)
    
operators = input("Enter the operators(in capitals) (AND / OR / NOT): ").split()

operators_stack = []
results_stack = []

try:
    for token in words + operators:
        if token in precedence:
            while (operators_stack and operators_stack[-1] in precedence and
                   precedence[operators_stack[-1]] >= precedence[token]):
                operator = operators_stack.pop()
                if operator == 'NOT':
                    v = results_stack.pop()
                    results_stack.append(logical_not(v))
                else:
                    v2 = results_stack.pop()
                    v1 = results_stack.pop()
                    if operator == 'AND':
                        results_stack.append(logical_and(v1, v2))
                    elif operator == 'OR':
                        results_stack.append(logical_or(v1, v2))
            operators_stack.append(token)
        else:
            v = matrix.get(token, [0] * n)
            results_stack.append(v)
except IndexError:
    print("Error: Incorrect expression or operator precedence.")

while operators_stack:
    operator = operators_stack.pop()
    if operator == 'NOT':
        v = results_stack.pop()
        results_stack.append(logical_not(v))
    else:
        v2 = results_stack.pop()
        v1 = results_stack.pop()
        if operator == 'AND':
            results_stack.append(logical_and(v1, v2))
        elif operator == 'OR':
            results_stack.append(logical_or(v1, v2))

if results_stack:
    print("Final Result:", results_stack[0])
else:
    print("No result available.")

    
#doc_1="breakthrough drug for schizophrenia"
#doc_2="new schizophrenia drug"
#doc_3="new approach for treatment of schizophrenia"
#doc_4="new hopes for schizophrenia patients"
