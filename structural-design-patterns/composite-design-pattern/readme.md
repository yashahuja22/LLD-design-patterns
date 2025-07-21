🧠 What is the Composite Pattern?

The Composite Design Pattern is used when you want to treat individual objects and groups of objects (composites) in the same way.

⸻

💡 Real-World Analogy: File System

Think of a file system:
	•	A File is a single item (like notes.txt)
	•	A Folder can contain Files or other Folders

But both can:
	•	show their name
	•	calculate their size
	•	be added to another folder

So, both File and Folder should implement the same interface.

Role                  Class
Component    ->       FileSystemItem
Leaf         ->       File
Composite    ->       Folder


The client treats both Files and Folders the same way via the FileSystemItem interface.
