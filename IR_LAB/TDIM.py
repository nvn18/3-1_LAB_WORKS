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
    
oper = input("Enter the operators(in capitals) (AND / OR / NOT): ").split()

query = input("Enter the query: ")


tokens = query.split()


oper_stk = []
res_stk = []

def fitting(oper):
    if oper == 'NOT':
        v = res_stk.pop()
        res_stk.append(logical_not(v))
    else:
        v2 = res_stk.pop()
        v1 = res_stk.pop()
        if oper == 'AND':
            res_stk.append(logical_and(v1, v2))
        elif oper == 'OR':
            res_stk.append(logical_or(v1, v2))


# Process tokens
try:
    for token in tokens:
        if token == '(':
            oper_stk.append(token)
            
        elif token == ')':
            while oper_stk and oper_stk[-1] != '(':
                oper = oper_stk.pop()
                fitting(oper)
            oper_stk.pop()
            
        elif token in precedence:
            while (oper_stk and oper_stk[-1] in precedence and
                   precedence[oper_stk[-1]] >= precedence[token]):
                oper = oper_stk.pop()
                fitting(oper)
            oper_stk.append(token)
            
        else:
            v = matrix.get(token, [0] * n)
            res_stk.append(v)
            
except IndexError:
    print("Error: Incorrect expression or operator precedence.")


while oper_stk:
    oper = oper_stk.pop()
    fitting(oper)


if res_stk:
    print("Final Result:", res_stk[0])
else:
    print("No result available.")

    
#doc_1="breakthrough drug for schizophrenia"
#doc_2="new schizophrenia drug"
#doc_3="new approach for treatment of schizophrenia"
#doc_4="new hopes for schizophrenia patients"
