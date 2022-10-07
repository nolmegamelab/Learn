from datetime import datetime

now = datetime.now()

fmt = "%H:%M:%S"

current_time = now.strftime(fmt)

target_time = "20:00:00"

tdelta = datetime.strptime(target_time, fmt) - datetime.strptime(current_time, fmt)

print(tdelta.total_seconds())