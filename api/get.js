fetch("https://jsonplaceholder.typicode.com/posts")
.then(res => res.json())
.then(json => console.log(json))
.catch(err => console.error(err.message));
