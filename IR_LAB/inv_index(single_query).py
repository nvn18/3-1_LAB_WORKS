#single query evalution:

inverted_index = {}

# Input documents
n = int(input("Enter the number of documents you want: "))
for i in range(n):
    doc_id = f"doc{i+1}"
    doc_content = input(f"Enter content for {doc_id}: ")
    terms = doc_content.lower().split()  
    for term in terms:
        if term not in inverted_index:
            inverted_index[term] = set()
        inverted_index[term].add(doc_id)

# Print the inverted index
print("Inverted Index:")
for term, doc_ids in inverted_index.items():
    print(f"{term}: {doc_ids}")



query = input("Enter the query:")
query_parts = query.split()
word1 = query_parts[0]
oper = query_parts[1]
word2 = query_parts[2]


if word1 in inverted_index:
    result = inverted_index[word1].copy()
else:
    result = set()


if word2 in inverted_index:
    if oper == "AND":
        result.intersection_update(inverted_index[word2])
    elif oper == "OR":
        result.update(inverted_index[word2])
    elif oper == "NOT":
        result.difference_update(inverted_index[word2])

# Display the resulting documents in a single line
if result:
    print("Documents satisfying the query:", end=" ")
    for doc_id in result:
        print(doc_id,"-->", end=" ")
else:
    print("no match found")
#"breakthrough drug for schizophrenia"
#"new schizophrenia drug"
#"new approach for treatment of schizophrenia"
#"new hopes for schizophrenia patients"
