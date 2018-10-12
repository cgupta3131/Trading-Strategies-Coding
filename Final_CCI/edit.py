import csv
name = input()
with open(name) as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    line_count = 0
    for row in csv_reader:
        if line_count == 0:
            line_count += 1
        else:
            print(f'{row[1]} {row[1]} {row[2]} {row[4]}')
            line_count += 1
   