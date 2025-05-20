fetch("https://jsonplaceholder.typicode.com/posts", {
	method: "POST",
	body: JSON.stringify({
		title: 'foo',
		body: 'bar',
		userId: 1
	}),
	header: {
		'Content-type': 'application/json; charset=UTF-8'
	}
})
.then(res => res.json())
.then(json => console.log(json))
.catch(err => console.error(err.message));