// react is a javascript library for building user interfaces , especially single page applications.It uses a component-based architecture and virtual DOM for fast rendering.

// react is a single page application --> react apps load one html page and dynamically update content without full page reload 

// virtual dom because real dom is slow 

// components are reusable pieces of UI => types: 1) functional components 2)class components 

// JSX -> javascript + html

// What are hooks?

// hooks allow functional components to usestate and lifecycle features 

// use state ==> used to manage the state  

const [count, setCount] = useState(0);

// useState updates are asynchronous because React batches updates for performance.

// setter function tells react ==> state has changed so please re-render the component. 

// use effect ==> used for (api calls , timers , life cycle methods)

// props => data passed from the parent , state = data stored in a component 

// how to call api ==>> using fetch/axios inside useeffect 

// react router -> used for navigation without page reload 

// api allows two applications to communicate with each other (it acts like a bridge betweeen frontend and the backend) => to get data from the server and to send the data to the server 

// REST APIS --> uses HTTP methods (get , post ,put , delete) 

// why react instead of angular --> lightweight , fast ,reusable components 

// redux is a state management library for large apps 

// context api is an api which avoids props drilling 

// props drilling ==> passing props to child and child and child 

// -----------------------Java script --------------------------

// what is js ?

// js is a high-level , interpreted , single threaded programming language used to build dynamic web applications

// Hoisting ==> js moves variable and function declarations to top of scope before excecution 

// == and === (compare values only , compare value and also the datatype)

// callback is a function passed as an arguement 

// promise is used to handle async operations 



// -------------------------------------------------------- NODE ---------------------------------------------------------------------------------------------------

// node.js is a runtime environment that allows javascript to run on server-side 

// fast , async , scalable

// nodejs is single threaded but handles multiple requests using event loop , call back queue , async operations

// modules are reusable code files 

// --------------------------------------------------------Express -------------------------------------------------------------------

// express is a node.js web framework used to build APIs and web applications easily 

// used for routing , middleware , apis , backend 

// with express easy routing , middleware suppport and fast api creation 

// routing is used to handle different urls 

// middlewares are the functions that run between response and the request 

// REST API is an api usiing http method 

// how authentication done --> JWT Token , login API , store token , verify token middleware 

// node vs express ==> node is a run time environment and express is framework on node 

// when a client sends request (client -> server -> routes -> middleware -> controller -> database -> response)

// how to make API faster? caching , async ,DB indexing 


// ---------------- crowinfra --------------------------

// 1) register/login (JWT authentication) 2) Add property or demand 3)upload images 4)give ratings 5)view listings

// Architecture --> there are three layers 1) frontend(next.js) 2)backend(node.js + express.js) 3)Database(mongoDB)

// user -> frontend -> API request -> backend routes -> controller -> MongoDB -> response -> frontend 

// why node.js => fast rendering , component reuse , better performance 

// why node js? (same language frontend and backend , good for restapis , npm system)

// express simplifies routing , middlewares , api creation , error handling 

// why mongoDB? easy with node , JSON-like data , NOSQL flexible schema , good for scalable apps 

// users , properties , demands , ratings 

// User logs in → backend verifies credentials → generates JWT token → token sent to frontend → stored in local storage → For protected routes token sent in header → middleware verifies token → if valid user allowed.

// auth middleware => verify JWT , multer middlewre => image upload , validation middleware => request validation 

// how image uploaded ? using multer middleware ==> frontend sends some data => multer stores image , path saved in mongoDB , image shown in frontend 

// what happends when an user adds property? => user fills the form -> frontend sends POST request -> backend route receives -> controller passes -> image upload handled -> data stored in mongoDB -> response sent 

// errors are handled using try-catch in controllers , proper status codes , middleware for error handling

// if 1 lakh users comes ==> load balancer , optimize queries , batabase indexing 

// how you secure backend => JWT Token , password hashing , validation middleware , protected routes 

// authentication = login , authorization = access control 

// get post put delete

// how to improve performance => lazy loading frontend , api optimization , DB indexing , caching 

// what challenges you have faced ==>  API integration , image upload handling , authentication errors , deployment issues 

// To improve performance of the website, I would optimize both frontend and backend , On the frontend, I would use lazy loading, code splitting, and reduce unnecessary re-renders , On the backend, I would optimize APIs, use caching, database indexing, and proper server scalin





