async function fetch_data(url) {
  try {
    const response = await fetch(url);
    if (!response.ok) throw new Error(`HTTP error! status: ${response.status}`);
    const data = await response.json(); // or response.text() if not JSON
    return { url, data };
  } catch (error) {
    return { url, error: error.message };
  }
}

async function fetch_all(urls) {
  const fetchPromises = urls.map(url => fetch_data(url));
  const results = await Promise.all(fetchPromises);
  return results;
}

const urls = [];
for(let i=1; i<=100; i++) {
  urls.push("https://jsonplaceholder.typicode.com/posts/" + i);
}

fetch_all(urls).then(results => {
  results.forEach(result => {
    if (result.error) {
      console.error(`${result.url} => Error: ${result.error}\n`);
    } else {
      console.log(`${result.url} => `, result.data, `\n`);
    }
  });
});