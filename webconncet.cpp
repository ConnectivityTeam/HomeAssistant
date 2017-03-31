#include "webconncet.h"

webconncet::webconncet()
{
    this->url;
    this->google_url = "https://www.google.de/?gws_rd=ssl#q=";
}

bool webconncet::search(string query)
{
    CURL *curl;
    CURLcode res;
    bool success = false;
    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(curl)
    {
      curl_easy_setopt(curl, CURLOPT_URL, this->url);

      /* Perform the request, res will get the return code */
      res = curl_easy_perform(curl);
      /* Check for errors */
      if(res != CURLE_OK)
      {
#ifdef DEBUG
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
#endif
      }
      else
      {
          success = true;
      }
      /* always cleanup */
      curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return success;
}
