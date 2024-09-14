# To-Do List Program

This project is a simple **To-Do List** program written in C++ that allows users to manage their tasks efficiently. The program enables users to add, view, edit, and delete tasks, with the tasks being saved in a file for future use.

## Features

- **Add New Tasks**: Users can add tasks with a priority, deadline, name, and description.
- **View Tasks**: Tasks are displayed in order of priority, helping users focus on the most important tasks first.
- **Edit Tasks**: Modify the description, deadline, and priority of existing tasks.
- **Delete Tasks**: Remove tasks that are no longer needed.
- **Persistent Storage**: Tasks are saved in a text file (`tasks.txt`) and can be loaded again when the program is restarted.

## How It Works

1. **Task Structure**: Each task contains:
   - Priority (integer)
   - Name (string)
   - Deadline (string in `yyyy-mm-dd` format)
   - Description (string)
   
2. **File Storage**: The program uses a text file (`tasks.txt`) to store tasks between sessions.
3. **Menu-Driven Interface**: The user interacts with the program through a simple menu system.

## Usage

1. Run the program.
2. Choose an option from the menu:
   - **1**: View all tasks.
   - **2**: Add a new task.
   - **3**: Delete a task.
   - **4**: Edit an existing task.
   - **0**: Exit the program.

3. The program will automatically save changes whenever tasks are added, edited, or deleted.

This program helps users manage their tasks by keeping track of deadlines and priorities in an organized way.

---
