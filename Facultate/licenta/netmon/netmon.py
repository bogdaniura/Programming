import curses
import threading
from scanner import scan_ports
from sniffer import start_sniffer
from connections import list_connections

def main(stdscr):
    curses.curs_set(0)
    stdscr.nodelay(1)
    stdscr.timeout(100)
    
    options = ["[1] Port Scanner", "[2] Live Traffic", "[3] Active Connections", "[Q] Quit"]
    selected = 0
    
    while True:
        stdscr.clear()
        for idx, option in enumerate(options):
            mode = curses.A_REVERSE if idx == selected else curses.A_NORMAL
            stdscr.addstr(idx, 0, option, mode)
        
        key = stdscr.getch()
        if key == ord("q"):
            break
        elif key == ord("1"):
            stdscr.clear()
            scan_ports("192.168.1.1")  # Change to user input
            stdscr.refresh()
        elif key == ord("2"):
            threading.Thread(target=start_sniffer, daemon=True).start()
        elif key == ord("3"):
            stdscr.clear()
            list_connections()
            stdscr.refresh()
    
curses.wrapper(main)
