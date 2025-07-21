🧠 Concept:

When you type a URL into a browser, like https://google.com, a lot happens behind the scenes:
	•	DNS resolution
	•	TCP connection setup
	•	Sending an HTTP request
	•	Rendering HTML, CSS, JavaScript

But you, as the user, just call openWebsite("google.com").
That’s the Facade Pattern — simplifying the complex process into a single interface.


✅ Components in Browser Example
🔧 Subsystems:
	•	DNSResolver — resolves the domain name.
	•	TCPConnection — establishes a connection to the server.
	•	HTTPRequest — sends and receives HTTP data.
	•	Renderer — renders the page to the screen.

🎯 Facade:
	•	Browser — provides a simple method: openWebsite("google.com").


🔍 Why Use Facade?

Without Browser, you’d call all four classes every time. With Browser, one call is enough — clean, readable, and user-friendly.