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
    query = input("Enter the query:\n")
    if query =="na valla kaadu":
        print("exiting program")
        break
    else:
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
                print(doc_id,"-->",end=" ")
        else:
            print("no match found")

                #print("the program executed successfully")

#"breakthrough drug for schizophrenia"
#"new schizophrenia drug"
#"new approach for treatment of schizophrenia"
#"new hopes for schizophrenia patients"
