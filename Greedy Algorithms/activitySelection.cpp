// Given N activities with their start and finish day given in array start[ ] and end[ ]. Select the maximum number of activities 
// that can be performed by a single person, assuming that a person can only work on a single activity at a given day.


#define ll long long int

class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    static bool comp(pair<ll, ll>&p1, pair<ll, ll>&p2) {
	return p1.second < p2.second;
}
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<ll, ll>>v(n);

		for (ll i = 0; i < n; i++) {
			v[i].first = start[i];
			v[i].second = end[i];
		}

		sort(v.begin(), v.end(), comp);

		ll ans = 1;
		ll last = v[0].second;
		for (ll i = 1; i < n; i++) {
			if (v[i].first > last) {
				ans++;
				last = v[i].second;
			}
		}
		return ans;
    }
};
