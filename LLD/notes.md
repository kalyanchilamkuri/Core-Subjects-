# SYSTEM DESIGN 

### system design is process of designing scalable,reliable,maintainable and software systems 
### It answers what components exists , how do they interact , how does system scale , stay available , and handle features 

# System design has 2 layers 1) LLD - code level design  2) HLD - architectural view

<!-- HLD => describes the architectural view , focuses on components , services , databases , communication not code  ==> like googel maps view of a city -->
<!-- LLD => low level design focuses on implementation ==> think of it like as the street view of a city -->

# UML Diagrams => uml diagrams are standard visual diagrams used to design and visualize => UML diagrams show how a system is structured and how it behaves before writing code.

<!-- 1️⃣ Clarify requirements
→ Use Case Diagram (mentally)

2️⃣ Design classes
→ Class Diagram

3️⃣ Explain flow
→ Sequence Diagram

4️⃣ Extend system
→ Modify Class Diagram -->















<!-- class -->





















<!-- solid principles -->

## solid is an acronym of 5 object-oriented design principles that help us write:
<!-- 1) maintainable code 2) flexible systems 3)scalable designs 4)testable components -->

# 1)S=>single responsibility principle (SRP)
## a class should have only one reason to change => each class should do one job only. 

<!-- class InvoiceCalculator {
    void calculateTotal() {}
}

class InvoicePrinter {
    void printInvoice() {}
}

class InvoiceRepository {
    void save() {}
} -->


## SRP matters ... easier debuggin , easier testing , changes dont break unrelated logic

# 2)O-Open/closed principle(OCP)
## software entities should be open for extension but closed for modification.

<!-- interface Payment {
    void pay();
}

class CardPayment implements Payment {
    public void pay() {}
}

class UpiPayment implements Payment {
    public void pay() {}
} -->


## Benefit ... No risk of breaking old code , plug-and-play extensions

# 3)L-Liskov substitution principle (LSP)
## subclasses should be replaceable by their parent class without breaking the program

<!-- interface Bird {}

interface FlyingBird extends Bird {
    void fly();
}

class Sparrow implements FlyingBird {}
class Penguin implements Bird {} -->

## penguin is a bird but cannot flu => violation 
## prevents runtime bugs and makes inheritance safe 

# I-Interface segregation principle(ISP)
## clients should not be forced to depend on interfaces they do not use 
## many small interfaces are better than one fat interface

<!-- interface Coder {
    void code();
}

interface Tester {
    void test();
}

interface Eater {
    void eat();
} -->

## clean implementations , no unnecessary methods , better readability

# D- Dependency inversion principle(DIP)

## High level modules should not depend on low-level modules , both should depend on abstractions 

<!-- interface Database {
    void save();
}

class MySQLDatabase implements Database {}

class UserService {
    Database db;
    UserService(Database db) {
        this.db = db;
    }
} -->

## DIP is powerful => easy to switch DBs , better unit testing , loose coupling
















































<!-- Design a systerm for managing the cricket match activity. Design a system like cricbuzz/cricinfo -->

<!-- Features -->

## Keep track of all formats. ODI, TESTT20
## Keep track of all the teams and their matches.
## Show ball by ball commentary of the match. 
## Team playing tournament should announce playing squad.
## Team playing match should announce playing eleven.
## Should record Stats of Players, Teams, Matches and tournaments.
## Should show the stats based on the query.

<!-- Assumptions -->

## There will be two teams playing in one match.
## For ODI, overs will be 50 and for T20 overs will be 20.
## Over will have 6 balls.
## Match will follow International rules.

<!-- class Diagram -->
<!-- when ever we are designing a class diagram first we should list down all the objects and features about that -->

## player , team , tournaments , match (t20,odi,test) , stats (player,team,tournament),overs,ball,commentary,commentator


















