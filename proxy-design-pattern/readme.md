✅ What is Proxy Design Pattern?

The Proxy Pattern provides a placeholder or surrogate for another object to control access to it.

You can think of it as a middleman between the client and the actual object.

⸻

🧠 Why Use It?

It’s useful when:
	•	You want to control access to an object.
	•	You want to add additional functionality (like logging, caching, security) without changing the real object.
	•	The real object is resource-heavy, and you want to delay its creation until needed.

🧾 Real-Life Analogy

Imagine a bank locker:
	•	You can’t access it directly.
	•	You request the bank staff (proxy) to open it for you.

Let’s say we have a RealImage class that loads a large image from disk. We’ll use a proxy to avoid loading the image until absolutely necessary.

Benefit                Description

Performance            Avoids unnecessary object loading

Security               Controls who can access the real object

Additional behavior    Logging, caching, or access control

Lazy initialization    Object is only created when needed


🧠 Summary
Role                    Class

Interface               Image
Real object             RealImage
Proxy                   ProxyImage
Client                  main()