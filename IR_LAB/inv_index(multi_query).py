inverted_index = {}

# Input documents
name = input("Enter the name of doc: ")
n = int(input("Enter the number of documents you want: "))
for i in range(n):
    doc_num = f"{name}{i+1}"
    doc_matter = input(f"Enter content for {doc_num}: ")
    terms = doc_matter.lower().split()  
    for t in terms:
        if t not in inverted_index:
            inverted_index[t] = set()
        inverted_index[t].add(doc_num)  

# Print the inverted index
print("Inverted Index:")
for term, doc_nums in inverted_index.items():
    print(f"{term}: {doc_nums}")

while True:
    query = input("Enter the query(to exit type 'na valla kaadu'): ")

    if query == 'na valla kaadu':
        print("Exiting the program.")
        break

    query_parts = query.split()

    if len(query_parts) != 3:
        print("Invalid query format.")
    else:
        word1 = query_parts[0]
        oper = query_parts[1]
        word2 = query_parts[2]

        # Initialize the result set with document IDs containing the first word
        if word1 in inverted_index:
            result = inverted_index[word1].copy()
        else:
            result = set()

        # Apply the operator to the result set and document IDs of the second word
        if word2 in inverted_index:
            if oper == "AND":
                result.intersection_update(inverted_index[word2])
            elif oper == "OR":
                result.update(inverted_index[word2])
            elif oper == "NOT":
                result.difference_update(inverted_index[word2])
            else:
                print("Invalid operator.")
        else:
            result = set()

        # Display the resulting documents in a single line
        if result:
            print("Documents satisfying the query:", end=" ")
            for doc_id in result:
                print(doc_id, "-->", end=" ")
            print()
        else:
            print("No documents satisfy the query.")

#"breakthrough drug for schizophrenia"
#"new schizophrenia drug"
#"new approach for treatment of schizophrenia"
#"new hopes for schizophrenia patients"
