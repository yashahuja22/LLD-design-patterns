--Applications of Chain of Responsibility Design Pattern
    Below are the applications of chain of responsibility design pattern:

    In graphical user interfaces (GUIs), events like mouse clicks or key presses can be handled by a chain of listeners. Each listener checks if it can handle the event, passing it along the chain if it can't. This way, multiple components can respond to the same event without being tightly linked.

    In logging systems, you might have different levels of loggers (like INFO, WARN, ERROR). Each logger can handle specific log messages. If one logger can’t process a message (for example, if it's below its level), it passes it to the next logger in the chain.

    In security systems, access requests can be processed by a series of handlers that check permissions. For instance, one handler might check user roles, while another checks specific permissions. If one handler denies access, it can pass the request to the next handler for further evaluation.