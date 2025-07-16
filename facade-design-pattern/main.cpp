#include <iostream>
using namespace std;

// Subsystem 1
class DNSResolver {
public:
    string resolveDomain(const string& domain) {
        cout << "Resolving domain: " << domain << endl;
        return "172.217.160.142"; // Fake IP for example
    }
};

// Subsystem 2
class TCPConnection {
public:
    void connect(const string& ip) {
        cout << "Establishing TCP connection to IP: " << ip << endl;
    }
};

// Subsystem 3
class HTTPRequest {
public:
    string get(const string& domain) {
        cout << "Sending HTTP GET request to: " << domain << endl;
        return "<html>Google Homepage</html>";
    }
};

// Subsystem 4
class Renderer {
public:
    void render(const string& html) {
        cout << "Rendering content: " << html << endl;
    }
};

// Facade
class Browser {
private:
    DNSResolver dns;
    TCPConnection tcp;
    HTTPRequest http;
    Renderer renderer;

public:
    void openWebsite(const string& domain) {
        string ip = dns.resolveDomain(domain);
        tcp.connect(ip);
        string html = http.get(domain);
        renderer.render(html);
    }
};

// Client Code
int main() {
    Browser chrome;
    chrome.openWebsite("google.com");

    return 0;
}