🧠 What is Mediator Design Pattern?

The Mediator pattern is used to reduce direct communication between objects. Instead of objects referring to each other directly, they communicate through a mediator object.

🤝 Analogy:

Imagine a chatroom where multiple people can send messages to each other.

Without a mediator, each person must know about all other participants.

With a mediator, everyone sends messages only to the chatroom, and the chatroom forwards the message to others.

⸻

🔧 When to Use
	•	When you have a lot of classes that interact with each other in complex ways.
	•	When changing one class forces you to change many others.
	•	When you want to centralize communication between objects.

⸻

✅ C++ Example: ChatRoom Mediator

👥 Participants:
	•	Mediator: ChatRoom
	•	Colleague: User