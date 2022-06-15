import win32process
import subprocess
import win32gui
import time 
import psutil
import os
import pyautogui
from datetime import datetime

def CheckTime(target_hour, target_minute):
  now = datetime.now()
  result = now.hour == target_hour and now.minute == target_minute
  return result

def WaitTime(target_hour, target_minute):
  while True:
    if CheckTime(target_hour, target_minute):
      return
    print("Waiting...")
    time.sleep(10)

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

def PrepareChrome():
  proc = None

  os.system("taskkill /f /im chrome.exe")

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

  return proc

def Enter(hour, minute):

  proc = PrepareChrome()

  print("Ready to enter office. Waiting...")

  WaitTime(hour, minute)

  pyautogui.click(150, 58)
  pyautogui.write("gwa.webzen.co.kr")
  pyautogui.press("enter")

  time.sleep(1)

  pyautogui.click(843, 406) # chrome
  # pyautogui.click(743, 526) # edge
  for i in range(0, 20):
    pyautogui.press("backspace")
  pyautogui.write("keedongpark")

  time.sleep(1)

  pyautogui.press('tab')
  for i in range(0, 20):
    pyautogui.press("backspace")
  pyautogui.write("6yhn&UJM") 

  pyautogui.click(823, 568) # chrome
  # pyautogui.click(743, 692) # edge

  time.sleep(5) # wait login

  pyautogui.click(88, 415) # click enter

  time.sleep(3) # wait popup

  pyautogui.click(697, 174) # confirm

  time.sleep(3) # wait complete

  pyautogui.click(778, 174) # 2nd confirm

  if proc is not None:
    proc.kill()

  print('Entered')

def Leave(hour, minute):

  proc = PrepareChrome()

  print("Ready to leave office. Waiting...")

  WaitTime(hour, minute)

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

  time.sleep(5) # wait login

  pyautogui.click(166, 415) # leave

  time.sleep(3) # wait popup

  pyautogui.click(697, 174) # confirm

  time.sleep(3) # wait complete

  pyautogui.click(778, 174) # 2nd confirm

  if proc is not None:
    proc.kill()

  print("Left")

# Leave(19, 15)

Enter(9, 10)

print("End")