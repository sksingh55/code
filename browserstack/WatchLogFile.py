import os
class WatchFile:
    def __init__(self,filepath):
        self._cached_stamp = 0
        self.filename = filepath

    def startWatching(self):
        while 1:
            stamp = os.stat(self.filename).st_mtime
            if stamp != self._cached_stamp:
                self._cached_stamp = stamp
                self.getLatestUpdates()

    def getLatestUpdates(self):
        with open(self.filename, 'rb') as f:
            f.seek(-2, os.SEEK_END)
            while f.read(1) != b'\n':
                f.seek(-2, os.SEEK_CUR) 
            print(f.readline().decode())

filepath = '/home/saurav/code/demo.cpp'
watchfile = WatchFile(filepath)
watchfile.startWatching()