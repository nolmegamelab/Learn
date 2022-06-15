import win32process
import subprocess
import win32gui
import time 
import psutil
import os
import pyautogui
 
def FindProcessByName(name):
  for pid in psutil.pids(): 
    try:
      if psutil.Process(pid).name() == name:
        return [True, pid]
    except:
      pass
  return [False, 0]

def GetWindowHandleByPid(pid):
  def Callback(hwnd, hwnds):
    _, found_pid = win32process.GetWindowThreadProcessId (hwnd)
    if found_pid == pid:
      hwnds.append (hwnd)
    return True
    
  output = []
  win32gui.EnumWindows(Callback, output)
  return output 

proc = None

r = FindProcessByName("chrome.exe")
if not r[0] : 
  proc = subprocess.Popen(r"C:\Program Files (x86)\Google\Chrome\Application\Chrome.exe")
  r = FindProcessByName("chrome.exe")

if not r[0]:
  print("Cannot start chrome or find one")
  exit(-1)

time.sleep(3)

hwnds = GetWindowHandleByPid(r[1])

if len(hwnds) == 0:
  print("Cannot find the window with pid")
  exit(-2)

# 너무 많은 윈도우가 크롬 안에 있다. 
for hwnd in hwnds:
  try:
    rect = win32gui.GetWindowRect(hwnd)
    text = win32gui.GetWindowText(hwnd)
    print(hwnd, "=>", text)
    #if True:
    if text == "New Tab - Google Chrome":
      win32gui.SetForegroundWindow(hwnd)
      win32gui.MoveWindow(hwnd, 0, 0, 1200, 800, True)
      # You need to test if your resolution really get exactly because mine is doesn't . 
      # I use . 16:9 Monitor , Calculate the percent using this calculations , , (x * .0204082) and (y * .0115774)
      tx = rect[0]
      ty = rect[1]
      print("top", tx, ty)
      print((hwnd, (rect[2] - rect[0], rect[3] - rect[1])))
      x = rect[2] - rect[0]
      y = rect[3] - rect[1]
      print(type(x), type(y))
  except:
    pass

pyautogui.click(150, 58)
pyautogui.write("gwa.webzen.co.kr")
pyautogui.press("enter")

time.sleep(1)

pyautogui.click(843, 406)
for i in range(0, 20):
  pyautogui.press("backspace")
pyautogui.write("keedongpark")

time.sleep(1)

pyautogui.press('tab')
for i in range(0, 20):
  pyautogui.press("backspace")
pyautogui.write("6yhn&UJM")

pyautogui.click(823, 568)

time.sleep(3) # wait login

pyautogui.click(88, 415)

time.sleep(3) # wait popup

pyautogui.click(697, 174)

if proc is not None:
  proc.kill()

print("End")