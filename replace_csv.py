f = open('out-classifier.csv', 'r')
out = open('cleaned-csv.csv', 'w')
for line in f:
    splits = line.split(", ")
    out.write(','.join(splits))
