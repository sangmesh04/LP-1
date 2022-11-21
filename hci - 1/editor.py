from tkinter import *
import tkinter as tk
from tkinter import filedialog
from tkinter.scrolledtext import ScrolledText
from tktooltip import ToolTip

root = Tk()
menu = Menu(root)
root.config(menu=menu)


def openFile():
   # filename = filedialog.askopenfilename(initialdir="/", title="select a file...",filetype=(("text", "*.txt*"), ("all types", "*.*")))
    print("Sangmeshwar Mahajan")


# navigation bar
filemenu = Menu(menu)
menu.add_cascade(label="File", menu=filemenu)
filemenu.add_command(label="New", command=openFile())
filemenu.add_command(label="New Window")
filemenu.add_command(label="Open", command=openFile())
filemenu.add_command(label="Save")
filemenu.add_command(label="Save as")
filemenu.add_separator()
filemenu.add_command(label="Exit", command=root.quit)
ToolTip(filemenu, msg="File options")

# editor menu bar
editmenu = Menu(menu)
menu.add_cascade(label="Edit", menu=editmenu)
editmenu.add_command(label="Undo", accelerator="Ctrl + Z")
editmenu.add_command(label="Redo", accelerator="Ctrl + Y")
editmenu.add_separator()
editmenu.add_command(label="Cut", accelerator="Ctrl+X")
editmenu.add_command(label="Copy", accelerator="Ctrl+C")
editmenu.add_command(label="Paste", accelerator="Ctrl+P")
editmenu.add_separator()
editmenu.add_command(label="Delete", accelerator="Del")
editmenu.add_command(label="Select All", accelerator="Ctrl+A")
ToolTip(editmenu, msg="Edit options")

# Format Menu
formatmenu = Menu(menu)
menu.add_cascade(label='Format', menu=formatmenu)
formatmenu.add_command(label='Word Wrap')
formatmenu.add_command(label='Font ...')
ToolTip(formatmenu, msg="Format Options")

# Help Menu
helpmenu = Menu(menu)
menu.add_cascade(label='Help', menu=helpmenu)
helpmenu.add_command(label='View Help')
helpmenu.add_command(label='Send Feedback')
helpmenu.add_command(label='About Notepad')
ToolTip(helpmenu, msg="Help Options")


text = ScrolledText(root, width=500, height=500, undo=True)
text.pack(fill=tk.BOTH)
mainloop()
