🧠 What is Flyweight Pattern?

The Flyweight Pattern is used to minimize memory usage by sharing common data between multiple objects instead of storing copies of the same data again and again.

It separates:
	•	Intrinsic data → shared and reused
	•	Extrinsic data → unique to each object, passed during use

⸻

💡 Real-life Example: Text Editor

In a text editor, when you type:
"HELLO"

Each character can be an object. But why create 5 separate objects for each L, E, O when they’re visually the same?

So:
	•	We create 1 object for each character (H, E, L, O) and reuse them.
	•	The position (x, y) is external (extrinsic) and given during rendering.

Part                        What it is
Flyweight         ->      Character – shared character object
Extrinsic State   ->      Position (x, y) – passed during display
Factory           ->      CharacterFactory – manages shared instances


🎯 When to Use Flyweight Pattern?
	•	When you have a large number of similar objects
	•	When objects can share common state
	•	Common in:
	•	Text rendering
	•	Game development (trees, tiles)
	•	Document editing