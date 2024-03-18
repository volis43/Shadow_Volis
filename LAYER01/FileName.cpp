#include <iostream>
#include <curl/curl.h>

using namespace std;

size_t write_data(void* ptr, size_t size, size_t nmemb, void* stream) {
    string* str = (string*)stream;
    *str += string((char*)ptr, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL* curl = curl_easy_init();
    if (curl) {
        string response;
        string student_id = "i22s0997";
        int command_number = 0; // Номер команды
        string url = "http://prog2.students.it-college.ru/api/w3t0/" + to_string(command_number);
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, ("Stud-ID: " + student_id).c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            cerr << "Error during curl request: " << curl_easy_strerror(res) << endl;
        }
        else {
            cout << "Response: " << response << endl;
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
    else {
        cerr << "Failed to initialize curl." << endl;
    }

    return 0;
}
