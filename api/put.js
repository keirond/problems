fetch("https://jsonplaceholder.typicode.com/posts/1", {
	method: "PUT",
	body: JSON.stringify({
		id: 1,
		title: 'foo',
		body: 'bar',
		userId: 1
	}),
	headers: {
		'Content-type': 'application/json; charset=UTF-8'
	}
})
.then(res => res.json())
.then(json => console.log(json))
.catch(err => console.error(err.message));