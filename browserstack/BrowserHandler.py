import os
import sqlite3
class Browser:
    selectedBrowser = ""

    def startBrowser(self,url):
        try:
            command = self.selectedBrowser + " --new-tab "+ url
            os.system(command);
        except:
            print("Unable to open browser")

    def stopBrowser(self):
        killUrl = "killall -9 " + self.selectedBrowser
        os.system(killUrl)

class Mozilla(Browser):
    dataPath = ""
    connection = object
    cursor = object
    def __init__(self):
        self.dataPath = os.path.expanduser('~')+'/.mozilla/firefox/z540bz4l.default-release/places.sqlite'
        self.connection = sqlite3.connect(self.dataPath)
        self.cursor = self.connection.cursor()
        self.selectedBrowser = "firefox"
        
    def getLatestUrl(self):
        select_statement ="select url from moz_places where ID = (SELECT MAX(ID) FROM moz_places);"
        self.cursor.execute(select_statement)
        results = self.cursor.fetchall()
        print(results)
    
    def clearHistory(self):
        select_statement = "delete from moz_places where id>0"
        self.cursor.execute(select_statement)
        self.connection.commit()

class Chrome(Browser):
    dataPath = ""
    connection = object
    cursor = object
    def __init__(self):
        self.dataPath = os.path.expanduser('~')+'/.config/google-chrome/Default/History'
        self.connection = sqlite3.connect(self.dataPath)
        self.cursor = self.connection.cursor()
        self.selectedBrowser = "google-chrome"
        
    def getLatestUrl(self):
        select_statement ="select url from urls where ID = (SELECT MAX(ID) FROM urls);"
        self.cursor.execute(select_statement)
        results = self.cursor.fetchall()
        print(results)
    
    def clearHistory(self):
        select_statement = "delete from urls"
        self.cursor.execute(select_statement)
        results = self.cursor.fetchall()
        self.connection.commit()

mozilla = Mozilla()
mozilla.startBrowser("www.google.com")
# mozilla.stopBrowser()
# mozilla.getLatestUrl()

# mozilla.clearHistory()
# chrome = Chrome()
# chrome.getLatestUrl()
# chrome.clearHistory()

            