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
  if now.hour > target_hour: 
    return True
  else: 
    if now.hour == target_hour:
      return now.minute >= target_minute
  return False

def IsAm():
  now = datetime.now()
  return now.hour < 12

def MoveMouse(): 
  x, y = pyautogui.position()
  pyautogui.moveTo(10, 10)
  pyautogui.moveTo(x, y)

def MoveKeyboard(): 
  pyautogui.press('left')
  pyautogui.press('right')

def WaitTime(target_hour, target_minute):
  while True:
    if CheckTime(target_hour, target_minute):
      return
    print("Waiting {:02}:{:02}".format(target_hour, target_minute))
    MoveKeyboard()
    time.sleep(30)

def WaitExactHour(target_hour):
  while True:
    now = datetime.now()
    if now.hour == target_hour: 
      return 
    print("Waiting {:02}".format(target_hour))
    MoveKeyboard()
    time.sleep(300)

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

  pyautogui.click(1852, 10)

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
      #print(hwnd, "=>", text)
      #if True:
      if text == "New Tab - Google Chrome":
        win32gui.SetForegroundWindow(hwnd)
        win32gui.MoveWindow(hwnd, 0, 0, 1200, 800, True)
        # You need to test if your resolution really get exactly because mine is doesn't . 
        # I use . 16:9 Monitor , Calculate the percent using this calculations , , (x * .0204082) and (y * .0115774)
        tx = rect[0]
        ty = rect[1]
        #print("top", tx, ty)
        #print((hwnd, (rect[2] - rect[0], rect[3] - rect[1])))
        x = rect[2] - rect[0]
        y = rect[3] - rect[1]
        #print(type(x), type(y))
    except:
      pass

  return proc

def Enter(user, pw, hour, minute):

  print("Entering...")

  WaitTime(hour, minute)

  proc = PrepareChrome()
  print("Ready to enter office.")
  time.sleep(5)

  pyautogui.click(150, 58)
  pyautogui.write("gwa.webzen.co.kr")
  pyautogui.press("enter")

  time.sleep(1)

  pyautogui.click(843, 406) # chrome
  # pyautogui.click(743, 526) # edge
  for i in range(0, 20):
    pyautogui.press("backspace")
  pyautogui.write(user)

  time.sleep(1)

  pyautogui.press('tab')
  for i in range(0, 20):
    pyautogui.press("backspace")
  pyautogui.write(pw)

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

def Leave(user, pw, hour, minute):
  print("Leaving...")

  WaitTime(hour, minute)

  proc = PrepareChrome()
  print("Ready to leave office.")

  time.sleep(5)

  pyautogui.click(150, 58)
  pyautogui.write("gwa.webzen.co.kr")
  pyautogui.press("enter")

  time.sleep(1)

  pyautogui.click(843, 406)
  for i in range(0, 20):
    pyautogui.press("backspace")
  pyautogui.write(user)

  time.sleep(1)

  pyautogui.press('tab')

  for i in range(0, 20):
    pyautogui.press("backspace")
  pyautogui.write(pw)

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


# enter_leave는 pyautogui를 사용하여 airtest와 같은 이미지와 
# 입력 기반의 테스트 자동화를 실험해 보기위해 만든 스크립트로 
# 출퇴근 어뷰징에 사용하거나 팀 외부에 유출하지 않아야 합니다. 

# 실행 시 크롬이 있어야 하고, 1920x1080 해상도에서 축소/확대가 없어야 
# 마우스 위치가 맞을 수 있으므로 자기 환경에 맞게 마우스 위치를 조절해야 합니다. 
# 또, 크롬이 최대 (maximzie)된 상태에 있으면 이동이 안 되어 동작하지 않습니다. 

# 실제 실행할 때 크롬을 모두 종료하므로 중요한 작업이 크롬에서 
# 실행될 경우 사용해서는 안 됩니다. 

# 여기에 설정한 사용자와 비번으로 로그인하고 지정한 시간까지 대기 후 실행합니다. 

config = {
  "user" : "keedongpark", 
  "pw" : "2wsx#EDC", 
  "enter" : {
    "hour" : 9, 
    "minute" : 30
  },
  "leave" : {
    "hour" : 18, 
    "minute" : 50 
  }
}

if IsAm(): 
  Enter(config["user"], config["pw"],  config["enter"]["hour"], config["enter"]["minute"])
  Leave(config["user"], config["pw"],  config["leave"]["hour"], config["leave"]["minute"])
else: 
  Leave(config["user"], config["pw"],  config["leave"]["hour"], config["leave"]["minute"])
  WaitExactHour(5)
  Enter(config["user"], config["pw"],  config["enter"]["hour"], config["enter"]["minute"])

print("End")