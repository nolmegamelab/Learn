import psutil

def findPath(name):
    for pid in psutil.pids():
        if psutil.Process(pid).name() == name:
            return psutil.Process(pid).exe()

print(findPath('chrome.exe'))