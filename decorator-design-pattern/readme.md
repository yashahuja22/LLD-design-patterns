✅ What is the Decorator Pattern?

The Decorator Pattern is used to add new behavior to an object without modifying its original structure or class.
It’s like wrapping an object with extra features at runtime.

🎯 Real-Life Example (Simple Analogy):

Imagine you’re ordering coffee:
	•	You start with a basic coffee.
	•	Then you want to add milk, sugar, or whipped cream.
	•	Each “add-on” doesn’t change the base coffee but just wraps more behavior around it.

    


Concept                  Meaning
Coffee                   Interface everyone follows
SimpleCoffee             Actual object you want to decorate
CoffeeDecorator          Base class that wraps a coffee
Milk, Sugar              Add-ons that extend behavior at runtime
Runtime Wrapping         You add features dynamically without changing the original class

💡 Why use this?
	•	To follow Open-Closed Principle: Open for extension, closed for modification.
	•	You don’t touch original classes but extend their behavior flexibly.