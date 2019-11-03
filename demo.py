import csv
path="/home/vassar/data/students data/ActiveStudents1718_Alldist/dbo_ActiveStudents1718_Alldistricts_7.csv"

reader = list(csv.reader(open(path, "rU"), delimiter=','))
writer = csv.writer(open(path, 'w'), delimiter=';')
writer.writerows(row for row in reader)