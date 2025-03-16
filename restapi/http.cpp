#include <bits/stdc++.h>
#include <curl/curl.h>

#include <nlohmann/json.hpp>

using namespace std;

using json = nlohmann::json;
constexpr char nl [[maybe_unused]] = '\n';

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
	size_t totalSize = size * nmemb;
	((std::string*)userp)->append((char*)contents, totalSize);
	return totalSize;
}

// TODO: hello

void solve() {
	CURL* curl = curl_easy_init();
	if (!curl) return;

	const string url = "https://jsonplaceholder.typicode.com/posts";
	json post_data = {{"title", "foo"}, {"body", "bar"}, {"userId", 1}};
	string post_data_str = post_data.dump();
	struct curl_slist* headers = nullptr;
	headers = curl_slist_append(headers, "Content-Type: application/json");

	string response;

	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	curl_easy_setopt(curl, CURLOPT_POST, 1L);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data_str.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

	CURLcode res = curl_easy_perform(curl);
	if (res != CURLE_OK) {
		cerr << "Curl request failed: " << curl_easy_strerror(res) << nl;
	} else {
		try {
			json response_json = json::parse(response);
			cout << response_json.dump(4) << nl;
		} catch (const exception& e) {
			cerr << "Failed to parse json: " << e.what() << nl;
		}
	}

	curl_easy_cleanup(curl);
	curl_slist_free_all(headers);
}

int main() {
	curl_global_init(CURL_GLOBAL_ALL);
	solve();
	curl_global_cleanup();
	cout << flush;
	return 0;
}