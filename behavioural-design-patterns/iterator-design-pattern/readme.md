✅ What is the Iterator Pattern?

The Iterator Pattern provides a way to access elements of a collection (like a list) one by one without exposing the internal structure of that collection.

It’s like a remote control that lets you go through items one at a time — without knowing how they’re stored inside.

⸻

🎯 Real-life Analogy:

Imagine a TV remote that can go to the next or previous channel.
You don’t care how the TV stores the channels — you just keep pressing Next or Previous.

⸻

🛠️ Components:
	1.	Iterator: Provides methods like hasNext() and next()
	2.	Collection: A class that stores a group of items and returns an iterator
	3.	Client: Uses the iterator to loop through items