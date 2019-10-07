import jaydebeapi

print("Starting")
db_path = "/home/vassar/Downloads/data/ActiveStudents1819_Alldist_9.accdb"

ucanaccess_jars = ["/home/vassar/Downloads/UCanAccess-4.0.4-bin/ucanaccess-4.0.4.jar",
                   "/home/vassar/Downloads/UCanAccess-4.0.4-bin/lib/commons-lang-2.6.jar",
                   "/home/vassar/Downloads/UCanAccess-4.0.4-bin/lib/commons-logging-1.1.3.jar",
                   "/home/vassar/Downloads/UCanAccess-4.0.4-bin/lib/hsqldb.jar",
                   "/home/vassar/Downloads/UCanAccess-4.0.4-bin/lib/jackcess-2.1.11.jar",
                   ]
print("Jar Loading")
classpath = ":".join(ucanaccess_jars)
print("Jar Loaded\nStarting database loading")
cnxn = jaydebeapi.connect(
    "net.ucanaccess.jdbc.UcanaccessDriver",
    f"jdbc:ucanaccess://{db_path};newDatabaseVersion=V2010",
    ["", ""],
    classpath
)
crsr = cnxn.cursor()
print(crsr.description)
print(crsr.rowcount)
print(crsr.fetchall)
print(crsr.execute("select * from dbo_ActiveStudents1819_Alldist_9; "))
# print("printing rows")
# crsr.execute("SELECT * FROM MSysObjects WHERE Type=1 AND Flags=0")
# for row in crsr.fetchall():
#     print(row)

 > sa2_file_upload_04July_1333.log &

Studentwise8thclassmarksforSA2


nohup sudo java -Xmx4304m -cp proj-apsea-launch-0.0.1-SNAPSHOT-jar-with-dependencies.jar com.vassarlabs.apsea.launch.APSEAFileUploadAndComputeUtils /home/vassar/Downloads/data/apseadata > sa2_file_upload_04July_1333.log &
Contents of launch.properties : 
AY=201819
AT=SA2
CT=null
SA=null
PA=null
IN=null
RP=null

Put “CT=assessment, SA=all”  for computation of student assessments.
Put “CT=peer, SA=all, PA=all” for computation of peer analysis.
Put “CT=interventions, SA=all, PA=all, IN=all” for computation of interventions.
Put “CT=report, SA=all, PA=all, IN=all, RP=all” for computation of trends.
Studentwise6thclassmarksforSA2


nohup sudo java -Xmx4304m -cp proj-apsea-launch-0.0.1-SNAPSHOT-jar-with-dependencies.jar com.vassarlabs.apsea.launch.APSEAFileUploadAndComputeUtils /home/vassar/Downloads/data/apseadata > sa2_file_upload_04July_1333.log &
