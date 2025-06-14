#include <bits/stdc++.h>
#define taskname ""
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen((string(taskname) + ".inp").c_str(), "r") != NULL) {
        freopen((string(taskname) + ".inp").c_str(), "r", stdin);
        freopen((string(taskname) + ".out").c_str(), "w", stdout);
    }
    
    ll n;
    string st;
    cin >> n;
    cin >> st;
    
    // Tạo mảng prefix sum cho từng ký tự
    vector<int> prefixA(n+1), prefixU(n+1), prefixG(n+1), prefixC(n+1);
    
    for (int i = 0; i < n; i++) {
        prefixA[i+1] = prefixA[i] + (st[i] == 'A');
        prefixU[i+1] = prefixU[i] + (st[i] == 'U');
        prefixG[i+1] = prefixG[i] + (st[i] == 'G');
        prefixC[i+1] = prefixC[i] + (st[i] == 'C');
    }
    
    ll maxLength = 0;
    
    // Với mỗi điểm bắt đầu
    for (int l = 0; l < n; l++) {
        // Binary search để tìm r xa nhất thỏa mãn điều kiện
        int left = l, right = n-1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int length = mid - l + 1;
            int required = length / 2 + 1;
            
            // Đếm số lần xuất hiện của mỗi ký tự trong đoạn [l, mid]
            int countA = prefixA[mid+1] - prefixA[l];
            int countU = prefixU[mid+1] - prefixU[l];
            int countG = prefixG[mid+1] - prefixG[l];
            int countC = prefixC[mid+1] - prefixC[l];
            
            int matchCount = 0;
            if (countA >= required) matchCount++;
            if (countU >= required) matchCount++;
            if (countG >= required) matchCount++;
            if (countC >= required) matchCount++;
            
            if (matchCount == 1) {
                // Đoạn hợp lệ, lưu kết quả và thử mở rộng
                maxLength = max(maxLength, (ll)length);
                left = mid + 1;
            } else {
                // Không hợp lệ, thu hẹp đoạn
                right = mid - 1;
            }
        }
    }
    
    cout << maxLength << endl;
    return 0;
}