import csv
import os


def opencsv(filename):
    f = open(filename, "r", encoding="UTF-8", errors="replace")
    reader = csv.reader(f)
    output = []
    for i in reader:
        output.append(i)
    f.close()
    return output


def writecsv(filename, the_list):
    f = open(filename, "w", newline="")
    csvob = csv.writer(f, delimiter=",")
    csvob.writerows(the_list)
    f.close()
    return csvob
