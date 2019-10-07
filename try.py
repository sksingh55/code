from poster.encode import multipart_encode
from poster.streaminghttp import register_openers
import urllib2

# Register the streaming http handlers with urllib2
register_openers()

# Use multipart encoding for the input files
datagen, headers = multipart_encode({'files[]': open(
    '/home/vassar/Downloads/data/ActiveStudents1819_Alldist_9.accdb', 'rb')})

# Create the request object
request = urllib2.Request(
    'https://www.rebasedata.com/api/v1/convert', datagen, headers)

# Do the request and get the response
# Here the ACCDB file gets converted to CSV
response = urllib2.urlopen(request)

# Check if an error came back
if response.info().getheader('Content-Type') == 'application/json':
    print(response.read())
    sys.exit(1)

# Write the response to /tmp/output.zip
with open('/tmp/output.zip', 'wb') as local_file:
    local_file.write(response.read())

print ('Conversion result successfully written to /tmp/output.zip!')

mdb-tables -1 ActiveStudents1819_Alldist_2.accdb

mdb-export ActiveStudents1819_Alldist_2.accdb 'dbo_ActiveStudents1819_Alldist_1' -H -D

mdb-tables -1 ActiveStudents1819_Alldist_9.accdb | while read -r tablename; do
     fname=$(echo "$tablename" | tr -d '()' | tr ' ' '_').csv
     echo "Extracting $tablename to $fname"
     mdb-export -D '%Y-%m-%d %H:%M:%S' ActiveStudents1819_Alldist_9.accdb "$tablename" > "$fname"
  done

