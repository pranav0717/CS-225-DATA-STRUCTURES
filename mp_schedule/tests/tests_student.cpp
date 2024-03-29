#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "schedule.h"
#include "tests_util.h"

// // You may write your own test cases in this file to test your code.
// // Test cases in this file are not graded.

// // TEST_CASE("My Test Case", "") {
// //     bool student_wrote_test_case = false;

// //     REQUIRE( student_wrote_test_case );
// // }
TEST_CASE("schedule() Private Test 3", "[weight=5]") {
    const V2D roster = {
{"CS548", "d3C0", "TM7K", "a4RM", "N6k6", "hFAu", "dBXW", "Rl3g", "fD9Z", "MMB7", "adsr", "3MkT", "1XyR", "iI5E", "whod", "i6kK", "Mvbp", "5awS", "Syfi", "ZtgA", "SOV3"}, \
{"CS559", "RCmw", "uJ1u", "oTvo", "9s72", "69FW", "O4S1", "j8hz", "1IyZ", "juE3", "R8qn", "KeOL", "NVDb", "oy72", "yEXC", "Fq5w", "TwXy", "GBaI", "z6u1", "JeKz", "6tfi"}, \
{"CS379", "pLop", "fSZA", "FfrR", "opIS", "uVxe", "4zro", "oUYx", "Oy0P", "RqDq", "GN6J", "jgYW", "gB3n", "n9fj", "21E1", "OYBf", "IsWN", "OgqX", "oC15", "fmWH", "oTvo"}, \
{"CS380", "pfWP", "SIpx", "HBYc", "hlAG", "Adfc", "sS7d", "iTna", "oRkX", "FZeI", "pXHK", "VzkD", "rL69", "WsxE", "3IhQ", "XwDd", "a4RM", "6JUh", "aSyw", "wINn", "SAxO"}, \
{"CS351", "x3RP", "TGri", "NuNh", "tOYU", "Fq5w", "Rl3g", "jBr3", "Tol9", "adsr", "gwwJ", "Z2AF", "EV2L", "fwJZ", "EAdJ", "MEqu", "3dWm", "97JV", "FcWt", "iI5E", "uecA"}, \
{"CS467", "KvCT", "aZps", "SepF", "Mvbp", "1N4w", "V3f2", "QkCN", "4h5Q", "QVbv", "BBuB", "LFer", "HbMa", "OtFy", "mTNz", "l5WH", "bfib", "Gco0", "d5Pj", "JeKz", "JDxM"}, \
{"CS140", "47eP", "MUX3", "D9wM", "4zro", "56Ty", "FpNN", "HBYc", "3dWm", "6ff1", "d5Pj", "nsb3", "GTEJ", "zBbr", "Ljaj", "LISe", "TIQp", "7Pbn", "J1hM", "ziyg", "hFAu"}, \
{"CS442", "sIEz", "mTNz", "amqP", "bQl8", "MUX3", "2QxZ", "oTvo", "MMB7", "IsWN", "oy72", "jHMO", "R1W3", "FCS5", "x3RP", "Tol9", "Fdyi", "xq8m", "FXKs", "zjOw", "XoaH"}, \
{"CS283", "mLwW", "zjOw", "ZtgA", "AkEq", "QSkb", "fS08", "iI5E", "X8op", "mYTT", "jHMO", "r8fw", "rZnn", "D9wM", "bq1K", "xfqv", "3zoy", "e7NC", "oUYx", "ZDVC", "sIEz"}, \
{"CS107", "aSyw", "RCmw", "n6dB", "mTNz", "2xij", "NvX0", "6qax", "e7NC", "PKJj", "69FW", "cFul", "bnUy", "LISe", "rwzr", "YXK5", "rL69", "uyJY", "dGzT", "b9hQ", "wtpY"}, \
{"CS126", "tomP", "QrRv", "1YEl", "xNG7", "oUYx", "1IyZ", "xxbr", "21E1", "PKJj", "NVDb", "0IWU", "LipO", "mYTT", "zBbr", "BjSI", "HBYc", "SOV3", "LyuS", "mANQ", "zjOw"}, \
{"CS180", "FZeI", "BjSI", "XoaH", "2nex", "RCmw", "8rFB", "Jurn", "hlAG", "XFBu", "LipO", "n6dB", "nsb3", "18f0", "8nhS", "yEXC", "EOdt", "9gXy", "kO5i", "RqDq", "2eOL"}, \
{"CS192", "H2lw", "uwbi", "9nGM", "BCEu", "adsr", "jx7Z", "7q0W", "GN6J", "uM1y", "GEc5", "qrEH", "PNZ3", "CkdE", "uPIj", "HCpb", "7kzp", "mSKm", "YYmn", "pXHK", "vWex"}, \
{"CS519", "h9hJ", "LyuS", "Fq5w", "ZtgA", "x53W", "mKxW", "7kzp", "rt4U", "bfib", "YmEO", "mwum", "zjOw", "d3C0", "IpXu", "s960", "hFAu", "H5le", "hlAG", "4h5Q", "pXHK"}, \
{"CS114", "pLop", "MVRK", "a4RM", "bQl8", "QVbv", "r59K", "8nVm", "7WCw", "1N4w", "BCEu", "Mq2U", "ocJu", "V3f2", "FCS5", "6tfi", "SUUJ", "aZps", "fS08", "2Sb0", "d20L"}, \
{"CS201", "VB9l", "0WNc", "6ff1", "jHMO", "YYmn", "9ihU", "OS1h", "scM0", "yc93", "FcWt", "5t1Q", "T2kW", "RQG6", "BeLR", "XUe8", "i6kK", "SOV3", "x53W", "mANQ", "vUUn"}, \
{"CS200", "VzkD", "fD9Z", "TwXy", "oVh9", "6MA1", "sKD8", "tOYU", "pS4p", "fwJZ", "IpXu", "QVbv", "oUYx", "bXFS", "SepF", "J9Az", "Bte6", "1XyR", "SI8N", "bbWT", "j8hz"}, \
{"CS428", "xDOz", "F98v", "GxJf", "3Paf", "oGrW", "TGri", "kfmo", "BAxY", "IsWN", "Swcq", "oy72", "xxbr", "UW8l", "TzU8", "MotW", "naD9", "mQbt", "XoaH", "0JDE", "Bz2H"}, \
{"CS533", "SUUJ", "N6k6", "IpXu", "ZtgA", "yEXC", "vWex", "sQTi", "2eOL", "1XyR", "9H0V", "lTNn", "FpNN", "D9wM", "sIEz", "uVxe", "GEc5", "Bte6", "opIS", "0JDE", "HL7e"}, \
{"CS118", "6I7D", "oRkX", "2owc", "iI5E", "RUjP", "ODzb", "nLla", "3ZJ7", "bbWT", "4ctV", "b9hQ", "ROr5", "PYRY", "dYAC", "pHmF", "wdsD", "V3f2", "oUYx", "CkdE", "uLl7"}, \
{"CS111", "BAxY", "8ROZ", "oFx6", "HbMa", "amqP", "DMVW", "KeOL", "MVRK", "Fdyi", "DfnM", "jx7Z", "0ADE", "j1zx", "VzkD", "nLla", "BEpM", "YYmn", "XJCj", "VRvZ", "kO5i"}, \
{"CS404", "v3Co", "jgYW", "oFx6", "5awS", "7ya5", "3MkT", "GTEJ", "KeOL", "QXzV", "e7NC", "JP5p", "mTNz", "FcWt", "J9Az", "jHMO", "DfnM", "4h5Q", "V3f2", "ao5n", "0ADE"}, \
{"CS375", "ynR2", "T2kW", "Oy0P", "bXFS", "JPj4", "YJsM", "ghtH", "iTna", "gFbQ", "pVKh", "bjC5", "H1Jp", "jlQH", "OtFy", "9s72", "KvCT", "GxJf", "vUUn", "mwum", "U0k4"}, \
{"CS182", "jWtw", "yc93", "69FW", "Ji16", "N6k6", "l5WH", "JPj4", "bQl8", "xxbr", "4YcB", "bhz7", "H1Jp", "XFBu", "scM0", "pMEZ", "a3Np", "ZIOi", "3BwP", "MF3D", "Ljaj"}, \
{"CS186", "BeLR", "Mq2U", "NVDb", "TolB", "vk2o", "PAZ7", "Oy0P", "BBuB", "FZeI", "pVKh", "jx7Z", "MMB7", "mTNz", "iI5E", "SAxO", "QVbv", "BEpM", "Bte6", "3s3I", "cD8q"}, \
{"CS574", "Bte6", "6ff1", "pT84", "9ihU", "qrEH", "ozad", "ZZlX", "AnwJ", "8ivC", "71BN", "Mz64", "VLHp", "DWp2", "EV2L", "U0k4", "KeOL", "hFAu", "PLfm", "QVbv", "r8fw"}, \
{"CS264", "NVDb", "RUjP", "dDZq", "BYOM", "rt4U", "9s72", "nLla", "EOdt", "JDxM", "xLNi", "3Paf", "kfmo", "47eP", "t8MR", "7Pbn", "Qnhq", "YnYf", "YYmn", "wINn", "hMuf"}, \
{"CS122", "adsr", "ziyg", "3ucd", "pfWP", "wtpY", "a3Np", "oFx6", "3s3I", "TTX5", "9ihU", "BeLR", "l5WH", "rL69", "j8hz", "fS08", "zwhj", "QVbv", "ZZlX", "NuNh", "lsA1"}, \
{"CS556", "XZG3", "lmrP", "Qtla", "RUjP", "r8fw", "i6kK", "MEqu", "bIJB", "s3KY", "XO4X", "YUsr", "aSyw", "6I7D", "HbMa", "xGIm", "pVKh", "mTNz", "1N4w", "T2kW", "5rZc"}, \
{"CS152", "2QxZ", "jBr3", "4zro", "e7NC", "JgfN", "liDl", "R1W3", "Oy0P", "mANQ", "GBaI", "uVxe", "4h5Q", "gwwJ", "XZG3", "VzkD", "fmWH", "H9LA", "8nhS", "kjo6", "BBuB"}, \
{"CS277", "3ucd", "7nGZ", "XBN0", "QSkb", "2giY", "KoA9", "EOdt", "2owc", "ZhIp", "a4RM", "3ZJ7", "ZTfk", "PKJj", "KAGX", "EAdJ", "JP5p", "1TKQ", "XwDd", "STL1", "TIQp"}, \
{"CS590", "fLS5", "vyyi", "ynR2", "DfnM", "oTvo", "KvRl", "pT84", "4Psl", "MF3D", "CL8o", "RHsm", "ao5n", "xxbr", "xTlb", "XFBu", "HbMa", "D9wM", "lsKU", "31vc", "whod"}, \
{"CS250", "eqFF", "QSkb", "BBuB", "X3bN", "OtFy", "8VYA", "Gco0", "3wWV", "DWp2", "7kzp", "x3RP", "7Pbn", "JPj4", "pXHK", "bjC5", "zvyh", "9gXy", "0BIc", "pfWP", "D9wM"}, \
{"CS500", "fwJZ", "scsz", "Ryli", "uM1y", "zBbr", "OYBf", "PAZ7", "XoaH", "l5WH", "Mz64", "elQD", "MotW", "4h5Q", "SUUJ", "iI5E", "paiz", "MF3D", "8ROZ", "3s3I", "QAJ8"}, \
{"CS429", "69FW", "2xij", "Qugo", "71BN", "ZTfk", "mANQ", "xNG7", "uFcH", "nLla", "XO4X", "bhz7", "SOV3", "S8pt", "8nVm", "7Pbn", "vUUn", "dDZq", "viWq", "wdsD", "pRJt"}, \
{"CS561", "8rFB", "n6dB", "sKD8", "sQTi", "scsz", "naD9", "bXFS", "CGB1", "1hha", "JDxM", "0GRK", "Fq5w", "xTlb", "n9fj", "znXW", "t8MR", "rZnn", "8VYA", "31vc", "wtpY"}, \
{"CS315", "bsTG", "6qax", "HL7e", "zjOw", "F98v", "9nGM", "pS4p", "Cbxl", "7Pbn", "Db6R", "8VYA", "BeLR", "sKD8", "OUoU", "Qulw", "5rZc", "3Paf", "vk2o", "HT2q", "5dI8"}, \
{"CS227", "6I7D", "TUj1", "pT84", "rwqL", "KvCT", "pHmF", "yyRu", "vk2o", "LyuS", "O0cW", "zBbr", "8nVm", "ozad", "dDZq", "18f0", "ODzb", "lsKU", "hMuf", "YYmn", "6rZu"}, \
{"CS402", "6ff1", "z6u1", "jgYW", "MotW", "69FW", "02wp", "ZhwU", "tOYU", "elQD", "jx7Z", "1TKQ", "1YEl", "vUUn", "a59u", "SI8N", "3Paf", "Jurn", "TGri", "S1Mg", "ZhIp"}, \
{"CS230", "a4RM", "2nex", "AGWD", "jHMO", "mT23", "sS7d", "GTEJ", "CL8o", "lTNn", "BjSI", "5dI8", "gwwJ", "wINn", "8VYA", "lsKU", "6l8Y", "3ZJ7", "KAGX", "wtpY", "ynCN"}, \
{"CS347", "2xij", "J1hM", "JeKz", "S93x", "QrRv", "iTna", "PLfm", "XZG3", "znXW", "y0qM", "Mdjb", "kfmo", "ZTfk", "UW8l", "AHcd", "mwum", "Ji16", "rt4U", "s960", "56Ty"}, \
{"CS113", "ynR2", "sUFF", "ocJu", "JP5p", "BCEu", "4Psl", "pVKh", "Bz2H", "ROr5", "4YcB", "3MkT", "whod", "69FW", "QrRv", "oUYx", "mSKm", "XJCj", "scsz", "9Ma6", "6rZu"}, \
{"CS583", "Qulw", "VRvZ", "7ya5", "HCpb", "XwDd", "1hha", "ROr5", "Fq5w", "pXHK", "whod", "71BN", "5dI8", "YUsr", "pMEZ", "Kp0g", "jHMO", "a3Np", "AHcd", "Yo4r", "OgqX"}, \
{"CS554", "IsWN", "dkH0", "uJ1u", "LipO", "NvX0", "xavH", "R1W3", "mQbt", "8ivC", "DMVW", "KsJx", "bsTG", "MUX3", "gwwJ", "Mvbp", "scM0", "21E1", "HCpb", "CkdE", "sIEz"}, \
{"CS213", "9Ma6", "xLNi", "Nn7v", "1hha", "XFBu", "S8pt", "3s3I", "8VYA", "WsxE", "e7NC", "1TKQ", "bmGD", "0Jn2", "uyJY", "LISe", "Bte6", "O0cW", "mTNz", "JeKz", "OS1h"}, \
{"CS587", "pS4p", "mKxW", "TUj1", "tk5C", "nsb3", "EOdt", "7q0W", "PKJj", "8ivC", "4YcB", "sS7d", "XJCj", "uyJY", "nLla", "4h5Q", "iQwu", "JDxM", "ROr5", "rZnn", "OYBf"}, \
{"CS162", "MVRK", "6qax", "dGzT", "t0uP", "oC15", "Yo4r", "xNG7", "FpNN", "WYAS", "aSyw", "HbMa", "ynR2", "7o0H", "Db6R", "H1Jp", "H2lw", "TTX5", "9s72", "X8op", "p0VW"}, \
{"CS596", "4ooO", "GBaI", "jBr3", "feJW", "mwum", "pSOP", "aZps", "jlQH", "Jurn", "SOV3", "5t1Q", "6ff1", "35Ut", "pRJt", "bhld", "KAGX", "1JGc", "BBuB", "sQTi", "7kzp"}, \
{"CS381", "GBaI", "dszu", "3ZJ7", "D9wM", "PYRY", "Nn7v", "9H0V", "3BwP", "bXFS", "Wkoj", "VRvZ", "1TKQ", "LFer", "7ya5", "j1zx", "sQTi", "Qtla", "1JGc", "GEc5", "fwJZ"}, \
{"CS492", "ozad", "oVh9", "bnUy", "QVbv", "R1W3", "MotW", "jBr3", "uVxe", "TTX5", "pfWP", "juE3", "UdgE", "RCmw", "zvyh", "dYAC", "j8hz", "pS4p", "GN6J", "vk2o", "1JGc"}, \
{"CS395", "SQ5b", "1IyZ", "KoA9", "LipO", "j8hz", "dREw", "JDxM", "2Psz", "vWex", "nLla", "OtFy", "3Paf", "iI5E", "Dgpy", "ZTfk", "pfWP", "bXFS", "T2kW", "TwXy", "pS4p"}, \
{"CS149", "NvX0", "mT23", "gBjO", "uecA", "CkdE", "RpfP", "aM8k", "T2kW", "LyuS", "ODzb", "TUj1", "ZDVC", "9gXy", "Rl3g", "Qnhq", "xLNi", "emEH", "uLl7", "pfWP", "3zoy"}, \
{"CS565", "9H0V", "2Psz", "zBbr", "2nex", "6MA1", "2Sb0", "JPj4", "GN6J", "gwwJ", "r59K", "RUjP", "MEqu", "8ROZ", "GBaI", "6FmO", "fSZA", "5t1Q", "SI8N", "4uOX", "BBuB"}, \
{"CS461", "LISe", "MotW", "H1Jp", "6FmO", "S93x", "KsJx", "ODzb", "y0qM", "TIQp", "Fdyi", "8nVm", "bmGD", "1N4w", "K7dm", "JC4Z", "c9Va", "BEpM", "Yo4r", "VB9l", "wdsD"}, \
{"CS297", "H1Jp", "MVRK", "lTNn", "1JGc", "71BN", "Syfi", "6rZu", "1VyX", "YUsr", "GEc5", "YnYf", "mKxW", "2owc", "rL69", "e7NC", "pHmF", "RqDq", "t8MR", "X3bN", "U0k4"}, \
{"CS579", "osZ3", "liDl", "Db6R", "mYTT", "Gco0", "WKog", "2nex", "yEXC", "XwDd", "adsr", "6rZu", "EYGM", "IpXu", "kO5i", "35Ut", "MVRK", "20lw", "Qnhq", "YnYf", "4uOX"}, \
{"CS209", "yyRu", "5t1Q", "18f0", "6MA1", "NnQU", "zBbr", "h9hJ", "1YEl", "fmWH", "NVDb", "0Jn2", "HIS6", "lsKU", "FCS5", "ym7q", "NvX0", "KsJx", "juE3", "Dgpy", "AkEq"}, \
{"CS498", "r59K", "CmyO", "7q0W", "zBbr", "DWp2", "j8hz", "ZtgA", "RQG6", "7o0H", "EEEi", "ynR2", "MF3D", "znXW", "7kzp", "9H0V", "tomP", "YXK5", "YDu0", "6ff1", "lTNn"}, \
{"CS203", "BYOM", "BCEu", "aM8k", "bfib", "EYGM", "xq8m", "4Psl", "jlQH", "ao5n", "x53W", "EEEi", "uM1y", "J0cA", "UdgE", "3Paf", "d3C0", "uFcH", "MEqu", "TM7K", "qiRp"}, \
{"CS321", "71BN", "H9LA", "p0VW", "yEXC", "r8fw", "VLHp", "GPlr", "s3KY", "a59u", "UdgE", "O0cW", "AHcd", "vyyi", "9nGM", "tomP", "2eOL", "lmrP", "xq8m", "PKJj", "cFul"}, \
{"CS131", "O0cW", "6tfi", "YXK5", "oUYx", "6FmO", "sIEz", "6I7D", "JP5p", "QkCN", "XBN0", "QAJ8", "lTNn", "BYOM", "1XyR", "uM1y", "6l8Y", "JC4Z", "35Ut", "Tol9", "TzU8"}, \
{"CS403", "sUFF", "6tfi", "2owc", "FpNN", "zaES", "rwqL", "XFBu", "BCEu", "bXFS", "S8pt", "mKxW", "O0cW", "gwwJ", "ZZlX", "FXKs", "S1Mg", "NuNh", "21E1", "J1hM", "4YcB"}, \
{"CS385", "Swcq", "H2lw", "x3RP", "jx7Z", "s960", "qiRp", "NvX0", "8nVm", "QVbv", "gBjO", "6rZu", "dGzT", "YucO", "bfib", "PAZ7", "WsxE", "8ivC", "bQl8", "6I7D", "hlAG"}, \
{"CS357", "YXK5", "HT2q", "uM1y", "bQl8", "CL8o", "dREw", "bIJB", "pHmF", "VB9l", "OYBf", "H5le", "KoA9", "GPlr", "mwum", "pMEZ", "IpXu", "7kzp", "gB3n", "a59u", "HIS6"}, \
{"CS247", "VRvZ", "NvX0", "E7tc", "rtVU", "CmyO", "JPj4", "Nn7v", "Mdjb", "Yo4r", "NnQU", "fLS5", "TM7K", "r59K", "oVh9", "97JV", "Jurn", "mTNz", "U0k4", "n6dB", "jgYW"}, \
{"CS239", "wyaj", "GEc5", "1XyR", "7kzp", "x3RP", "dkH0", "xavH", "FZeI", "ziyg", "Lyf8", "NVDb", "JaTp", "8nVm", "DMVW", "3ZJ7", "RQG6", "emEH", "jHMO", "XoaH", "wdsD"}, \
{"CS193", "ZIOi", "quXk", "xLNi", "7kzp", "3BwP", "ZhIp", "7nGZ", "RpfP", "gwwJ", "zvyh", "RCmw", "O4S1", "aM8k", "XBN0", "0JDE", "XO4X", "viWq", "xxbr", "FXKs", "KoA9"}, \
{"CS352", "8nhS", "ZIOi", "QrRv", "CmyO", "BAxY", "mSKm", "QXzV", "LyuS", "h9hJ", "3s3I", "aSyw", "z7VO", "wdsD", "8nVm", "vPK5", "pfWP", "6hGX", "bhld", "VRvZ", "pHmF"}, \
{"CS367", "VLHp", "adsr", "GxJf", "0GRK", "t0uP", "CkdE", "FXKs", "FpNN", "XUe8", "QkCN", "tOYU", "2owc", "35Ut", "EOdt", "d5Pj", "AkEq", "jBr3", "OtFy", "MF3D", "VB9l"}, \
{"CS168", "YUsr", "STL1", "HL7e", "Mdjb", "pfWP", "c9Va", "J9Az", "4ctV", "xLNi", "vk2o", "qrEH", "naD9", "JDxM", "jjIY", "zwhj", "BAxY", "XUe8", "Jurn", "YucO", "PAZ7"}, \
{"CS475", "H2lw", "FCS5", "7nGZ", "H9LA", "z7VO", "FarL", "jjIY", "JSKP", "bQl8", "vUUn", "2eOL", "5yBo", "TwXy", "Krpo", "SepF", "lTNn", "7q0W", "5t1Q", "0Jn2", "rZnn"}, \
{"CS211", "elQD", "69FW", "liDl", "uwbi", "Bte6", "HBYc", "h9hJ", "2Sb0", "kJar", "gB3n", "oFx6", "7Pbn", "fSZA", "xxbr", "9gXy", "HbMa", "GxJf", "O8fZ", "NvX0", "YUsr"}, \
{"CS150", "R8qn", "1VyX", "02wp", "YnYf", "97JV", "uecA", "K7dm", "Oy0P", "LFer", "3s3I", "X3bN", "z7VO", "ym7q", "8nhS", "Qugo", "BjSI", "RCmw", "EYGM", "SQ5b", "Rl3g"}, \
{"CS580", "GTEJ", "lmrP", "uwbi", "DMVW", "mANQ", "FfrR", "wxcC", "RqDq", "r8fw", "BeLR", "wINn", "dBXW", "Qugo", "mT23", "wdsD", "zOzo", "CJlj", "1Xrc", "KoA9", "TIQp"}, \
{"CS317", "5t1Q", "JC4Z", "joc4", "jlQH", "6l8Y", "Tol9", "Nn7v", "n6dB", "wyaj", "Adfc", "mYTT", "8ROZ", "sKD8", "CmyO", "ZZlX", "0BIc", "FCS5", "ynR2", "4ctV", "NvX0"}, \
{"CS443", "bXFS", "69FW", "OS1h", "5t1Q", "SAxO", "Mz64", "oUYx", "Mvbp", "mSKm", "0GRK", "DWp2", "HCpb", "6MA1", "BCEu", "uPIj", "3s3I", "H1Jp", "iQwu", "dGzT", "mwum"}, \
{"CS389", "mYTT", "nLla", "oC15", "9H0V", "TIQp", "dYAC", "pT84", "6FmO", "9ihU", "AHcd", "GxJf", "H5le", "2eOL", "8rFB", "kjo6", "d20L", "SIpx", "yyRu", "Syfi", "1hha"}, \
{"CS294", "k0s8", "zBbr", "paiz", "dkH0", "5Arz", "b9hQ", "Mz64", "RHsm", "5dI8", "JgfN", "x53W", "Qnhq", "69FW", "cWTD", "quXk", "4uOX", "scM0", "sS7d", "LyuS", "bmGD"}, \
{"CS529", "dGzT", "rt4U", "69FW", "BeLR", "scsz", "BjSI", "HCpb", "pVKh", "Ji16", "MVRK", "SepF", "JC4Z", "zOzo", "rL69", "Z2AF", "XUe8", "mLwW", "0WNc", "wINn", "MotW"}, \
{"CS183", "s960", "TIQp", "GEc5", "T2kW", "u1H6", "6JUh", "sQTi", "uyJY", "jWtw", "Lyf8", "KAGX", "cWTD", "Nn7v", "iI5E", "0JDE", "p0VW", "6ZdG", "j8hz", "r59K", "mSKm"}, \
{"CS147", "mSKm", "aM8k", "3zoy", "pT84", "z6u1", "XJCj", "KsJx", "WYAS", "SQ5b", "2QxZ", "Cbxl", "Gco0", "FCpF", "uFcH", "S93x", "71BN", "zjOw", "amqP", "AGWD", "k0s8"}, \
{"CS474", "oUYx", "5t1Q", "OgqX", "fLS5", "8rFB", "ozad", "6qax", "QAJ8", "xLNi", "J0cA", "9s72", "oy72", "JDxM", "z7VO", "SIpx", "Ji16", "mTNz", "FarL", "WKog", "JaTp"}, \
{"CS584", "SepF", "2giY", "Db6R", "mSKm", "0JDE", "sKD8", "JgfN", "oUYx", "AkEq", "6JUh", "QXzV", "ZhIp", "rwqL", "a3Np", "ZhwU", "scM0", "x3RP", "8VYA", "3ucd", "RCmw"}, \
{"CS560", "SAxO", "ym7q", "Db6R", "mKxW", "oVh9", "MVRK", "rtVU", "MEqu", "sIEz", "TIQp", "LISe", "MUX3", "0GRK", "NVDb", "6JUh", "wdsD", "69FW", "gwwJ", "eqFF", "tomP"}, \
{"CS354", "5t1Q", "T2kW", "SOV3", "DWp2", "gFbQ", "BAxY", "MF3D", "YYmn", "xq8m", "7nGZ", "jBr3", "F98v", "FpNN", "MVRK", "TTX5", "MMB7", "BBuB", "Wkoj", "3BwP", "8ivC"}, \
{"CS504", "quXk", "oVh9", "jWtw", "9s72", "j8hz", "sQTi", "EEEi", "c9Va", "pVKh", "gBjO", "bnUy", "E7tc", "YucO", "pT84", "osZ3", "21E1", "ROr5", "n9fj", "rwqL", "5t1Q"}, \
{"CS324", "pLop", "6l8Y", "0BIc", "RCmw", "bsTG", "r59K", "ZhIp", "kJar", "CmyO", "3IhQ", "j1zx", "MVRK", "6qax", "naD9", "CGB1", "kjo6", "oVh9", "p0VW", "QSkb", "hFAu"}, \
{"CS215", "56Ty", "6JUh", "BBuB", "3s3I", "7q0W", "NuNh", "bIJB", "XZG3", "naD9", "S8pt", "4YcB", "X8op", "dYAC", "VB9l", "cD8q", "vWex", "kjo6", "wxcC", "osZ3", "8nVm"}, \
{"CS303", "ZDVC", "1VyX", "gB3n", "7o0H", "MF3D", "Mvbp", "H2lw", "4YcB", "MVRK", "6qax", "mTNz", "Qnhq", "oC15", "YucO", "jHMO", "3dWm", "V3f2", "dGzT", "FCpF", "ZIOi"}, \
{"CS290", "3IhQ", "1N4w", "emEH", "KeOL", "tomP", "t8MR", "4ctV", "PAZ7", "8nVm", "n9fj", "LyuS", "FCpF", "gB3n", "Cbxl", "WKog", "bnUy", "Rk1T", "4Psl", "GxJf", "HCpb"}, \
{"CS138", "GN6J", "ZIOi", "K7dm", "0ADE", "RqDq", "47eP", "rtVU", "Adfc", "bbWT", "iI5E", "YJsM", "YnYf", "S1Mg", "UW8l", "bsTG", "hMuf", "CkdE", "XZG3", "FCpF", "WsxE"}, \
{"CS161", "7Pbn", "uyJY", "IpXu", "uM1y", "pVKh", "PYRY", "EOdt", "Ljaj", "JP5p", "hMuf", "bhz7", "EAdJ", "FCS5", "ZDVC", "6hGX", "CL8o", "CkdE", "TGri", "elQD", "T2kW"}, \
{"CS576", "rwqL", "Rk1T", "YDu0", "cFul", "K7dm", "n6dB", "YJsM", "1hha", "zOzo", "7q0W", "a4RM", "sS7d", "T2kW", "SI8N", "Dgpy", "YXK5", "OS1h", "xTlb", "9nGM", "21E1"}, \
{"CS494", "1IyZ", "LyuS", "STL1", "n6dB", "VLHp", "RCmw", "Tol9", "yc93", "6hGX", "1hha", "XJCj", "jBr3", "ynR2", "XFBu", "Mdjb", "JeKz", "YUsr", "b662", "SOV3", "D9wM"}, \
{"CS333", "znXW", "iTna", "z6u1", "7WCw", "6ff1", "quXk", "1TKQ", "VzkD", "1YEl", "iI5E", "0IWU", "e7NC", "fS08", "ZtgA", "lsKU", "feJW", "jBr3", "Ceu7", "N6k6", "wxcC"}, \
{"CS221", "Db6R", "AnwJ", "CmyO", "d20L", "JaTp", "hFAu", "MMB7", "l5WH", "iI5E", "oFx6", "jHMO", "oTvo", "pS4p", "cf9V", "aM8k", "fS08", "i6kK", "juE3", "YXK5", "uwbi"}, \
{"CS246", "RqDq", "Dgpy", "MF3D", "35Ut", "b9hQ", "Syfi", "i6kK", "xavH", "5awS", "7kzp", "sUFF", "Z2AF", "bnUy", "KsJx", "jWtw", "3BwP", "vWex", "TolB", "KvRl", "j1zx"}, \
{"CS368", "zwhj", "XBN0", "ziyg", "3ucd", "FarL", "YJsM", "3s3I", "FfrR", "dREw", "OgqX", "8nhS", "cf9V", "R8qn", "RQG6", "aZps", "3wWV", "mwum", "zvyh", "3zoy", "SAxO"}, \
{"CS160", "zwhj", "YYmn", "d20L", "t8MR", "E7tc", "FZeI", "8sZ1", "MEqu", "pT84", "GN6J", "nLla", "zvyh", "sQTi", "YJsM", "ut8L", "Rk1T", "NnQU", "71BN", "znXW", "eqFF"}, \
{"CS415", "Lyf8", "Cbxl", "KsJx", "VLHp", "47eP", "Qugo", "UW8l", "Bz2H", "cWTD", "n9fj", "u1H6", "dDZq", "zwhj", "adsr", "2xij", "02wp", "Adfc", "e7NC", "l5WH", "OYBf"}, \
{"CS251", "bbWT", "tOYU", "J9Az", "GPlr", "O4S1", "jjIY", "RqDq", "X3bN", "EEEi", "Yo4r", "2xij", "oTvo", "ZTfk", "1Xrc", "scsz", "VLHp", "MF3D", "ZhwU", "ozad", "dszu"}, \
{"CS558", "oFx6", "eqFF", "Syfi", "YnYf", "hFAu", "FfrR", "RCmw", "dREw", "1VyX", "oRkX", "lsKU", "y0qM", "20lw", "SIpx", "2eOL", "d3C0", "2QxZ", "H5le", "6I7D", "VB9l"}, \
{"CS130", "IsWN", "PYRY", "KAGX", "uPIj", "2QxZ", "Swcq", "iTna", "9nGM", "NnQU", "cf9V", "sQTi", "XwDd", "H5le", "9gXy", "Bz2H", "mLwW", "4YcB", "rL69", "xq8m", "iQwu"}, \
{"CS521", "a59u", "2nex", "31vc", "0GRK", "PNZ3", "opIS", "fSZA", "tOYU", "zvyh", "jBr3", "HT2q", "XBN0", "FXKs", "YXK5", "0ADE", "lTNn", "Lyf8", "OgqX", "3MkT", "K7dm"}, \
{"CS448", "VRvZ", "9s72", "Syfi", "H5le", "d5Pj", "OtFy", "pSOP", "bQl8", "U0k4", "xDOz", "PAZ7", "YucO", "2xij", "3IhQ", "SI8N", "dYAC", "FZeI", "h9hJ", "0WNc", "BEpM"}, \
{"CS578", "WYAS", "iTna", "oTvo", "fS08", "rL69", "Mq2U", "dBXW", "jBr3", "UdgE", "amqP", "2nex", "bIJB", "scM0", "4YcB", "18f0", "FpNN", "EV2L", "t8MR", "xLNi", "31vc"}, \
{"CS265", "rZnn", "18f0", "qiRp", "bnUy", "fSZA", "KvRl", "3ZJ7", "oUYx", "r59K", "k0s8", "lsA1", "cFul", "6ff1", "02wp", "ODzb", "V3f2", "XoaH", "zaES", "pSOP", "0ADE"}, \
{"CS408", "0BIc", "cFul", "GN6J", "OYBf", "O4S1", "BCEu", "69FW", "MF3D", "7nGZ", "liDl", "zaES", "xDOz", "WsxE", "0IWU", "RCmw", "Fdyi", "Jurn", "whod", "OtFy", "9nGM"}, \
{"CS170", "pVKh", "GN6J", "1N4w", "3Paf", "amqP", "YJsM", "Wkoj", "qrEH", "2nex", "FXKs", "MotW", "SepF", "n6dB", "uFcH", "FCS5", "71BN", "sQTi", "NvX0", "3BwP", "cf9V"}, \
{"CS210", "MEqu", "oy72", "zBbr", "BjSI", "mT23", "iI5E", "oRkX", "LFer", "Syfi", "XUe8", "3MkT", "hMuf", "5t1Q", "kO5i", "ZZlX", "Lyf8", "Wkoj", "y0qM", "3Paf", "FXKs"}, \
{"CS445", "rL69", "juE3", "Mvbp", "mANQ", "8ivC", "elQD", "fLS5", "oC15", "bq1K", "l5WH", "2owc", "znXW", "r59K", "ZtgA", "MVRK", "oFx6", "YucO", "6tfi", "mTNz", "Kp0g"}, \
{"CS383", "adsr", "2Sb0", "3BwP", "71BN", "oC15", "uM1y", "JSKP", "RQG6", "jBr3", "1VyX", "2QxZ", "7WCw", "EV2L", "cWTD", "ZhIp", "MotW", "v3Co", "O0cW", "JC4Z", "FfrR"}, \
{"CS543", "9nGM", "FpNN", "7ya5", "1Xrc", "iQwu", "dREw", "Lyf8", "GPlr", "s960", "1IyZ", "lsA1", "TM7K", "BeLR", "AnwJ", "bfib", "3IhQ", "56Ty", "BjSI", "y0qM", "z6u1"}, \
{"CS473", "31vc", "WYAS", "ZrRK", "XoaH", "QAJ8", "6hGX", "GBaI", "a59u", "mSKm", "Jurn", "JeKz", "X8op", "D9wM", "1VyX", "bbWT", "t0uP", "RqDq", "9s72", "2xij", "KvRl"}, \
{"CS470", "uVxe", "PKJj", "d5Pj", "bXFS", "7Pbn", "ao5n", "AkEq", "2giY", "y0qM", "3ZJ7", "YucO", "AHcd", "Ceu7", "Ji16", "BeLR", "bfib", "ocJu", "7ya5", "Jurn", "O8fZ"}, \
{"CS540", "qiRp", "opIS", "Ji16", "3dWm", "Jurn", "r8fw", "PKJj", "b9hQ", "znXW", "Qtla", "tOYU", "uFcH", "bsTG", "Krpo", "xGIm", "YucO", "XZG3", "Bte6", "R8qn", "fD9Z"}, \
{"CS421", "oUYx", "HbMa", "jjIY", "vWex", "BBuB", "TM7K", "TUj1", "56Ty", "k0s8", "xTlb", "GEc5", "mTNz", "tomP", "CmyO", "Jurn", "kjo6", "XoaH", "hFAu", "O0cW", "eqFF"}, \
{"CS595", "oUYx", "r59K", "XFBu", "V3f2", "3BwP", "k0s8", "jjIY", "IpXu", "YmEO", "4ctV", "HBYc", "ynCN", "gFbQ", "KvRl", "QSkb", "osZ3", "VRvZ", "Bte6", "UdgE", "t0uP"}, \
{"CS127", "uM1y", "1JGc", "5Arz", "WKog", "AnwJ", "T2kW", "4h5Q", "JaTp", "6FmO", "ocJu", "VLHp", "uVxe", "7ya5", "jBr3", "3ucd", "pVKh", "Oy0P", "9s72", "SepF", "H2lw"}, \
{"CS243", "2eOL", "BBuB", "elQD", "hMuf", "6FmO", "U0k4", "9FG3", "mKxW", "z6u1", "JeKz", "N6k6", "XBN0", "HIS6", "v3Co", "viWq", "sQTi", "aM8k", "kO5i", "1TKQ", "QXzV"}, \
{"CS222", "xfqv", "xavH", "Ceu7", "02wp", "QSkb", "SQ5b", "nsb3", "d3C0", "9ihU", "3ucd", "E7tc", "BeLR", "Swcq", "IpXu", "VzkD", "scsz", "LFer", "uLl7", "RQG6", "OYBf"}, \
{"CS153", "7q0W", "MUX3", "TM7K", "U0k4", "Qnhq", "XO4X", "47eP", "znXW", "0Jn2", "ZhwU", "SAxO", "scM0", "9ihU", "Syfi", "uPIj", "uyJY", "1XyR", "rZnn", "9FG3", "V3f2"}, \
{"CS100", "bXFS", "MF3D", "UW8l", "xfqv", "GPlr", "bhld", "r59K", "Mz64", "bmGD", "YucO", "Tol9", "MEqu", "XjrB", "NVDb", "a3Np", "HIS6", "T2kW", "CJlj", "PNZ3", "xavH"}, \
{"CS437", "K7dm", "9gXy", "hlAG", "VRvZ", "p0VW", "GxJf", "jx7Z", "0JDE", "02wp", "D9wM", "oC15", "ZhVz", "amqP", "QrRv", "ym7q", "6ZdG", "Mz64", "6hGX", "yyRu", "RpfP"}, \
{"CS176", "F98v", "MF3D", "HT2q", "4h5Q", "ODzb", "MVRK", "lsA1", "OgqX", "iI5E", "1JGc", "xq8m", "Qnhq", "2Psz", "QVbv", "uVxe", "jlQH", "mQbt", "KvCT", "quXk", "dDZq"}, \
{"CS350", "4ooO", "BjSI", "PNZ3", "ynCN", "whod", "ZIOi", "fLS5", "QrRv", "BCEu", "naD9", "vUUn", "zBbr", "dGzT", "Mdjb", "dkH0", "vk2o", "iI5E", "6rZu", "31vc", "9nGM"}, \
{"CS164", "J0cA", "PLfm", "X8op", "OYBf", "6MA1", "CmyO", "kfmo", "QkCN", "8ROZ", "feJW", "rtVU", "Ljaj", "9ihU", "S93x", "pRJt", "bQl8", "bsTG", "0IWU", "YucO", "S1Mg"}, \
{"CS298", "lTNn", "YYmn", "Lyf8", "RQG6", "Qtla", "HBYc", "juE3", "HIS6", "02wp", "ZtgA", "Bte6", "jWtw", "6qax", "8ROZ", "Fq5w", "Yo4r", "uVxe", "GPlr", "D9wM", "CmyO"}, \
{"CS263", "mYTT", "5Arz", "jHMO", "1N4w", "Cbxl", "NuNh", "uPIj", "1Xrc", "Nn7v", "UdgE", "18f0", "liDl", "iQwu", "ut8L", "dYAC", "uecA", "Fdyi", "opIS", "oFx6", "mANQ"}, \
{"CS520", "8nVm", "20lw", "8ivC", "joc4", "02wp", "tk5C", "FfrR", "QkCN", "OYBf", "Dgpy", "H2lw", "QAJ8", "YucO", "Rk1T", "EAdJ", "sS7d", "2QxZ", "OS1h", "jHMO", "PKJj"}, \
{"CS549", "FcWt", "c9Va", "0GRK", "VB9l", "OUoU", "BCEu", "NVDb", "Mdjb", "XUe8", "yyRu", "BjSI", "9nGM", "ROr5", "Yo4r", "S1Mg", "r8fw", "CGB1", "SIpx", "BAxY", "Ji16"}, \
{"CS369", "Db6R", "YJsM", "d20L", "9Ma6", "uPIj", "xfqv", "joc4", "R1W3", "r59K", "31vc", "6I7D", "6ff1", "1JGc", "qozS", "t0uP", "FpNN", "5t1Q", "ZTfk", "sUFF", "lsA1"}, \
{"CS129", "t8MR", "fSZA", "xLNi", "HCpb", "Nn7v", "opIS", "GBaI", "TUj1", "IsWN", "xavH", "b662", "bhz7", "CmyO", "Jurn", "ROr5", "H2lw", "BeLR", "ao5n", "ZtgA", "xq8m"}, \
{"CS218", "XUe8", "xDOz", "xTlb", "QXzV", "zaES", "EOdt", "dszu", "4zro", "O4S1", "wyaj", "Krpo", "BeLR", "zvyh", "uLl7", "u1H6", "2xij", "jBr3", "KvCT", "6JUh", "fLS5"}, \
{"CS422", "YDu0", "k0s8", "97JV", "uM1y", "MVRK", "ynCN", "wdsD", "0JDE", "oy72", "8rFB", "Jurn", "n6dB", "y0qM", "pRJt", "D9wM", "3BwP", "Ljaj", "AkEq", "RCmw", "Mdjb"}, \
{"CS447", "gFbQ", "Tol9", "uwbi", "rt4U", "Kp0g", "bnUy", "r59K", "ZrRK", "GEc5", "6hGX", "qozS", "paiz", "TolB", "9s72", "d5Pj", "wdsD", "1JGc", "k0s8", "Syfi", "ZDVC"}, \
{"CS425", "lmrP", "7q0W", "S93x", "mANQ", "iI5E", "dszu", "Mvbp", "GPlr", "9Ma6", "2Psz", "bfib", "elQD", "4YcB", "FCpF", "QXzV", "wyaj", "jBr3", "bsTG", "9s72", "JC4Z"}, \
{"CS364", "x53W", "ynCN", "a59u", "4Psl", "47eP", "d3C0", "Ji16", "HBYc", "quXk", "R1W3", "uFcH", "HbMa", "kJar", "uwbi", "YYmn", "SUUJ", "pHmF", "SepF", "sS7d", "wyaj"}, \
{"CS232", "zjOw", "tOYU", "JPj4", "LISe", "ROr5", "X3bN", "FpNN", "CL8o", "VRvZ", "UW8l", "fD9Z", "rwqL", "scM0", "Fq5w", "0BIc", "kfmo", "mTNz", "NVDb", "RHsm", "NvX0"}, \
{"CS413", "9Ma6", "D9wM", "QXzV", "2owc", "n9fj", "oy72", "J9Az", "zjOw", "CJlj", "ZDVC", "lmrP", "pT84", "JDxM", "6FmO", "PAZ7", "a59u", "0JDE", "YJsM", "XoaH", "3BwP"}, \
{"CS330", "VRvZ", "pMEZ", "3zoy", "KAGX", "1JGc", "Fq5w", "dGzT", "JC4Z", "6FmO", "HL7e", "TGri", "4zro", "RpfP", "qiRp", "D9wM", "j1zx", "gBjO", "zjOw", "uLl7", "H2lw"}, \
{"CS511", "R1W3", "1N4w", "dBXW", "8ivC", "a4RM", "71BN", "UW8l", "lTNn", "lmrP", "nLla", "CJlj", "OtFy", "4ctV", "joc4", "Jurn", "Mvbp", "7o0H", "XBN0", "DfnM", "rtVU"}, \
{"CS534", "LipO", "uyJY", "hlAG", "9s72", "21E1", "18f0", "bhld", "t0uP", "7o0H", "KAGX", "QVbv", "mSKm", "8nVm", "z7VO", "uLl7", "4uOX", "p0VW", "gwwJ", "WKog", "GN6J"}, \
{"CS163", "FZeI", "vk2o", "a3Np", "fLS5", "Rk1T", "jgYW", "aZps", "QVbv", "O0cW", "BYOM", "H1Jp", "zvyh", "XO4X", "fwJZ", "b662", "Ceu7", "6JUh", "ynCN", "uJ1u", "elQD"}, \
{"CS256", "21E1", "FcWt", "xavH", "UW8l", "zOzo", "5dI8", "3BwP", "YYmn", "Db6R", "1N4w", "ozad", "d3C0", "Mdjb", "1TKQ", "KAGX", "J1hM", "O8fZ", "9nGM", "vUUn", "6I7D"}, \
{"CS320", "rL69", "NuNh", "mQbt", "Z2AF", "4YcB", "5Arz", "OtFy", "AHcd", "j1zx", "Mq2U", "ROr5", "s3KY", "OUoU", "zBbr", "F98v", "uJ1u", "9gXy", "Ljaj", "3ucd", "LFer"}, \
{"CS365", "3s3I", "Ljaj", "ZIOi", "6JUh", "8ivC", "BEpM", "QSkb", "ziyg", "c9Va", "Qugo", "Qnhq", "QXzV", "TM7K", "oC15", "pMEZ", "69FW", "ym7q", "uwbi", "AnwJ", "kJar"}, \
{"CS273", "gwwJ", "z7VO", "ZtgA", "J9Az", "3ucd", "EV2L", "Kp0g", "cFul", "FXKs", "XFBu", "EYGM", "DfnM", "Rl3g", "jWtw", "8nVm", "CL8o", "GxJf", "S93x", "tOYU", "d3C0"}, \
{"CS370", "Ljaj", "ut8L", "XwDd", "QXzV", "vWex", "jgYW", "7o0H", "1Xrc", "fD9Z", "amqP", "3ucd", "pT84", "mANQ", "MMB7", "bbWT", "2eOL", "scsz", "znXW", "lsA1", "6qax"}, \
{"CS300", "3ZJ7", "EV2L", "S8pt", "uJ1u", "mwum", "TIQp", "qrEH", "3Paf", "YnYf", "WKog", "r8fw", "pS4p", "OgqX", "SQ5b", "ROr5", "8sZ1", "2giY", "STL1", "Rl3g", "a3Np"}, \
{"CS581", "whod", "Z2AF", "iI5E", "JDxM", "d20L", "3wWV", "yEXC", "DfnM", "SQ5b", "pVKh", "XO4X", "IsWN", "7q0W", "CGB1", "gB3n", "oVh9", "yyRu", "h9hJ", "20lw", "sQTi"}, \
{"CS600", "wdsD", "tk5C", "Bz2H", "bsTG", "0IWU", "71BN", "0JDE", "elQD", "TTX5", "FfrR", "SepF", "r8fw", "GEc5", "EOdt", "p0VW", "Qulw", "HbMa", "sKD8", "ZhwU", "paiz"}, \
{"CS387", "uM1y", "18f0", "bnUy", "O8fZ", "eqFF", "J0cA", "QSkb", "4ctV", "WYAS", "CL8o", "DWp2", "naD9", "Syfi", "Dgpy", "F98v", "Fdyi", "joc4", "H9LA", "Mdjb", "pT84"}, \
{"CS272", "vPK5", "oC15", "Bte6", "yyRu", "eqFF", "IpXu", "JSKP", "ZZlX", "7kzp", "scM0", "RHsm", "E7tc", "aM8k", "kjo6", "jBr3", "sQTi", "dYAC", "Bz2H", "6I7D", "uJ1u"}, \
{"CS598", "HT2q", "6FmO", "Cbxl", "JP5p", "WYAS", "0ADE", "dGzT", "a59u", "uecA", "KAGX", "uPIj", "47eP", "5Arz", "AHcd", "fmWH", "XJCj", "TzU8", "z6u1", "xLNi", "7nGZ"}, \
{"CS535", "cWTD", "SAxO", "JP5p", "fSZA", "vUUn", "joc4", "YUsr", "Z2AF", "8ROZ", "n9fj", "pS4p", "Mvbp", "1Xrc", "Qugo", "Ljaj", "vk2o", "Fdyi", "YmEO", "AkEq", "pHmF"}, \
{"CS342", "paiz", "cFul", "pMEZ", "r59K", "H9LA", "oy72", "8ROZ", "Swcq", "SepF", "uJ1u", "KAGX", "LipO", "a4RM", "Rl3g", "Kp0g", "MMB7", "pVKh", "IpXu", "S1Mg", "ZhIp"}, \
{"CS154", "ynCN", "oy72", "gBjO", "KeOL", "xavH", "XJCj", "AHcd", "PAZ7", "lsA1", "8nVm", "vPK5", "dGzT", "2Psz", "cf9V", "d20L", "joc4", "5Arz", "nsb3", "Rk1T", "aZps"}, \
{"CS419", "EAdJ", "bq1K", "RUjP", "oTvo", "r59K", "rL69", "PKJj", "Ji16", "6I7D", "uM1y", "Kp0g", "FCS5", "TM7K", "HL7e", "Db6R", "EV2L", "kJar", "rtVU", "1IyZ", "6qax"}, \
{"CS530", "mSKm", "pT84", "4ooO", "dYAC", "35Ut", "KvRl", "lsKU", "7q0W", "tk5C", "vyyi", "ynCN", "MVRK", "SUUJ", "F98v", "Gco0", "y0qM", "fD9Z", "H1Jp", "kO5i", "uVxe"}, \
{"CS206", "JSKP", "2owc", "1IyZ", "gFbQ", "X8op", "opIS", "VRvZ", "Ji16", "i6kK", "Bte6", "aZps", "Cbxl", "dGzT", "E7tc", "71BN", "WYAS", "T2kW", "TwXy", "b9hQ", "4h5Q"}, \
{"CS165", "FcWt", "MVRK", "oUYx", "4Psl", "4uOX", "Syfi", "JPj4", "IpXu", "bXFS", "QAJ8", "Fdyi", "Rk1T", "bjC5", "v3Co", "4h5Q", "fwJZ", "PYRY", "3Paf", "iQwu", "x3RP"}, \
{"CS171", "lmrP", "71BN", "GTEJ", "S93x", "AkEq", "ghtH", "OYBf", "Qugo", "0GRK", "Cbxl", "Qulw", "K7dm", "EOdt", "xDOz", "NvX0", "bhz7", "XFBu", "18f0", "Db6R", "X3bN"}, \
{"CS293", "yyRu", "mANQ", "Mvbp", "oUYx", "bQl8", "1YEl", "7o0H", "S93x", "oy72", "WsxE", "JeKz", "SepF", "NvX0", "SQ5b", "F98v", "i6kK", "RCmw", "PLfm", "pRJt", "bq1K"}, \
{"CS135", "OtFy", "rt4U", "Qnhq", "FarL", "quXk", "zwhj", "QXzV", "PLfm", "3ucd", "X3bN", "ROr5", "z6u1", "z7VO", "HbMa", "sUFF", "dGzT", "TTX5", "VB9l", "0Jn2", "Gco0"}, \
{"CS435", "fS08", "xq8m", "3Paf", "O8fZ", "6tfi", "JC4Z", "hlAG", "9Ma6", "dszu", "Jurn", "RQG6", "mANQ", "X3bN", "XoaH", "GN6J", "1hha", "QAJ8", "FcWt", "3IhQ", "cWTD"}, \
{"CS289", "Ceu7", "e7NC", "nsb3", "bq1K", "QAJ8", "21E1", "YYmn", "8VYA", "opIS", "JPj4", "jWtw", "SOV3", "hFAu", "rt4U", "1VyX", "rwqL", "xq8m", "4Psl", "fSZA", "QSkb"}, \
{"CS516", "ozad", "3ucd", "N6k6", "Mq2U", "Syfi", "aZps", "bhz7", "wdsD", "SIpx", "vyyi", "YJsM", "XUe8", "T2kW", "uFcH", "jBr3", "sS7d", "7nGZ", "3Paf", "lmrP", "xq8m"}, \
{"CS308", "pRJt", "bbWT", "bhld", "RCmw", "CL8o", "S1Mg", "feJW", "WKog", "jgYW", "SOV3", "oGrW", "a3Np", "56Ty", "fLS5", "sQTi", "bjC5", "8VYA", "xq8m", "zOzo", "TzU8"}, \
{"CS121", "mKxW", "Ceu7", "7q0W", "BBuB", "gB3n", "EAdJ", "fmWH", "VB9l", "3ZJ7", "1JGc", "h9hJ", "Db6R", "kjo6", "zOzo", "znXW", "CkdE", "EOdt", "qozS", "oVh9", "ut8L"}, \
{"CS426", "Ryli", "bfib", "RQG6", "7ya5", "jlQH", "ym7q", "aZps", "ZDVC", "O8fZ", "PKJj", "XZG3", "JgfN", "mwum", "jgYW", "VB9l", "mSKm", "Ljaj", "N6k6", "1IyZ", "vPK5"}, \
{"CS338", "4Psl", "3BwP", "c9Va", "5yBo", "HCpb", "KsJx", "UW8l", "BCEu", "TIQp", "4ctV", "cf9V", "Tol9", "wyaj", "EYGM", "z6u1", "JSKP", "r8fw", "2Psz", "GxJf", "XoaH"}, \
{"CS478", "69FW", "ZIOi", "1VyX", "LyuS", "p0VW", "XjrB", "bhld", "bfib", "yc93", "Dgpy", "FcWt", "ZTfk", "HIS6", "0IWU", "Kp0g", "8sZ1", "pLop", "n9fj", "MVRK", "TM7K"}, \
{"CS323", "ODzb", "XUe8", "U0k4", "LISe", "pHmF", "mTNz", "r59K", "ziyg", "MotW", "5Arz", "EAdJ", "ocJu", "dszu", "e7NC", "lTNn", "c9Va", "scM0", "Mq2U", "5dI8", "iI5E"}, \
{"CS483", "YJsM", "HIS6", "oRkX", "ut8L", "FarL", "XO4X", "H2lw", "9FG3", "CGB1", "iI5E", "Jurn", "joc4", "quXk", "dREw", "VRvZ", "4zro", "YucO", "d5Pj", "fS08", "wxcC"}, \
{"CS234", "d3C0", "2xij", "WYAS", "TwXy", "paiz", "n9fj", "Oy0P", "wINn", "wdsD", "SIpx", "liDl", "WKog", "xfqv", "nsb3", "MotW", "OUoU", "KvCT", "uecA", "vUUn", "bIJB"}, \
{"CS522", "joc4", "ziyg", "xfqv", "eqFF", "5yBo", "CmyO", "rL69", "pHmF", "qrEH", "NuNh", "LISe", "GTEJ", "Ryli", "OtFy", "FfrR", "pXHK", "RQG6", "cWTD", "FarL", "4YcB"}, \
{"CS539", "jHMO", "joc4", "mYTT", "LISe", "naD9", "jx7Z", "8nhS", "71BN", "6ZdG", "2xij", "sIEz", "nsb3", "6MA1", "rwqL", "Mz64", "6FmO", "eoE6", "6hGX", "ynCN", "pHmF"}, \
{"CS528", "Cbxl", "wdsD", "ynCN", "R1W3", "S1Mg", "SepF", "9Ma6", "BEpM", "EEEi", "znXW", "VLHp", "vPK5", "JeKz", "aZps", "1N4w", "1Xrc", "XJCj", "s960", "FfrR", "J9Az"}, \
{"CS420", "NuNh", "bq1K", "QrRv", "aZps", "Yo4r", "LISe", "jWtw", "bbWT", "iI5E", "Z2AF", "kO5i", "x3RP", "dREw", "SQ5b", "21E1", "RUjP", "juE3", "2Psz", "vWex", "mQbt"}, \
{"CS166", "9ihU", "V3f2", "BeLR", "b9hQ", "MotW", "O0cW", "5Arz", "69FW", "6ZdG", "Gco0", "Tol9", "qrEH", "xq8m", "FCS5", "8ROZ", "xNG7", "fmWH", "uM1y", "Ceu7", "8sZ1"}, \
{"CS235", "BEpM", "eoE6", "paiz", "6I7D", "YnYf", "sS7d", "XBN0", "fS08", "1JGc", "d3C0", "KsJx", "h9hJ", "t0uP", "UW8l", "k0s8", "JSKP", "TGri", "VLHp", "3ucd", "pXHK"}, \
{"CS497", "eqFF", "FarL", "ZhIp", "fS08", "TwXy", "bIJB", "z6u1", "V3f2", "r59K", "8nVm", "TM7K", "6JUh", "b662", "XBN0", "joc4", "Rk1T", "ZrRK", "9ihU", "hMuf", "dDZq"}, \
{"CS310", "5awS", "tomP", "pfWP", "s3KY", "1YEl", "KvCT", "0JDE", "AHcd", "j1zx", "uFcH", "31vc", "PAZ7", "21E1", "d3C0", "YUsr", "rwzr", "lsKU", "YXK5", "XjrB", "fmWH"}, \
{"CS589", "wINn", "vPK5", "t8MR", "EYGM", "FCpF", "fSZA", "4YcB", "2Psz", "Ceu7", "xDOz", "jx7Z", "scsz", "CkdE", "gBjO", "ozad", "5dI8", "k0s8", "x3RP", "adsr", "ziyg"}, \
{"CS334", "hFAu", "JaTp", "Gco0", "d3C0", "gBjO", "pMEZ", "N6k6", "SI8N", "zvyh", "YnYf", "e7NC", "t8MR", "XjrB", "TIQp", "qozS", "ynR2", "XoaH", "Krpo", "amqP", "GTEJ"}, \
{"CS466", "ZDVC", "UdgE", "3dWm", "31vc", "2xij", "Ji16", "BYOM", "18f0", "6MA1", "osZ3", "b662", "YDu0", "Cbxl", "6ZdG", "zBbr", "EOdt", "zjOw", "vWex", "vPK5", "CL8o"}, \
{"CS464", "pSOP", "YnYf", "bmGD", "O4S1", "l5WH", "S8pt", "CkdE", "1N4w", "ROr5", "ghtH", "1JGc", "DMVW", "NVDb", "ODzb", "CJlj", "XwDd", "QkCN", "21E1", "s3KY", "a59u"}, \
{"CS322", "NVDb", "2eOL", "0IWU", "cWTD", "j8hz", "EAdJ", "ziyg", "MUX3", "BCEu", "Kp0g", "TIQp", "osZ3", "CJlj", "Fdyi", "NnQU", "y0qM", "YJsM", "XjrB", "WYAS", "sQTi"}, \
{"CS373", "KsJx", "UdgE", "MMB7", "VLHp", "tk5C", "aM8k", "4ooO", "MVRK", "cD8q", "97JV", "ODzb", "iTna", "mANQ", "6rZu", "SepF", "BYOM", "Swcq", "MotW", "2owc", "d3C0"}, \
{"CS502", "Rl3g", "nsb3", "qiRp", "yEXC", "4ooO", "H2lw", "D9wM", "0WNc", "HCpb", "8rFB", "AnwJ", "21E1", "BeLR", "vWex", "r8fw", "J0cA", "6I7D", "wtpY", "GxJf", "6ZdG"}, \
{"CS291", "NvX0", "fLS5", "TTX5", "ZrRK", "EYGM", "RqDq", "3BwP", "4uOX", "GN6J", "BCEu", "pRJt", "cD8q", "CJlj", "Z2AF", "mSKm", "2eOL", "8rFB", "KAGX", "oVh9", "gFbQ"}, \
{"CS397", "20lw", "vWex", "GN6J", "eoE6", "rt4U", "21E1", "GEc5", "tk5C", "XwDd", "3wWV", "BjSI", "3MkT", "SQ5b", "YJsM", "bhld", "69FW", "HCpb", "97JV", "pRJt", "JPj4"}, \
{"CS468", "Ceu7", "XBN0", "v3Co", "XUe8", "TolB", "9ihU", "Dgpy", "7WCw", "rt4U", "oVh9", "QVbv", "KeOL", "PYRY", "ZZlX", "VB9l", "Nn7v", "scsz", "kfmo", "5yBo", "bfib"}, \
{"CS555", "dYAC", "qozS", "Syfi", "1Xrc", "5awS", "VLHp", "mTNz", "fS08", "naD9", "MUX3", "QAJ8", "O4S1", "5Arz", "E7tc", "AkEq", "z7VO", "K7dm", "dszu", "Ji16", "viWq"}, \
{"CS460", "d20L", "iI5E", "xNG7", "hlAG", "YJsM", "xq8m", "UW8l", "n6dB", "5dI8", "Mz64", "3IhQ", "naD9", "qrEH", "7nGZ", "dGzT", "kJar", "jBr3", "mANQ", "jlQH", "dYAC"}, \
{"CS207", "0GRK", "dYAC", "mTNz", "XwDd", "IpXu", "zjOw", "oGrW", "gB3n", "uyJY", "YJsM", "4uOX", "bXFS", "cFul", "35Ut", "STL1", "BCEu", "bmGD", "cf9V", "Krpo", "pXHK"}, \
{"CS304", "gB3n", "KsJx", "KvCT", "p0VW", "GEc5", "tomP", "6qax", "47eP", "scsz", "1hha", "STL1", "Qtla", "kO5i", "HBYc", "S93x", "fmWH", "nLla", "BBuB", "d20L", "QrRv"}, \
{"CS105", "7Pbn", "fSZA", "ROr5", "fLS5", "d20L", "QXzV", "LyuS", "1TKQ", "SIpx", "ghtH", "D9wM", "3IhQ", "6FmO", "4Psl", "Nn7v", "1IyZ", "z7VO", "JeKz", "cWTD", "O0cW"}, \
{"CS197", "dszu", "6rZu", "l5WH", "4uOX", "b662", "3IhQ", "2Sb0", "Bte6", "t0uP", "viWq", "GTEJ", "pMEZ", "pSOP", "KAGX", "H5le", "tk5C", "9ihU", "6I7D", "ynCN", "KoA9"}
};

    std::vector<std::string> timeslots;
    // This is actually an approx test -- mine could do this in 42 colors
    // (and potentially there's an even smaller option brute forced)
    int slots = 45; 
    for(int i = 0; i < slots; i++){
        timeslots.push_back(std::to_string(i));
    }

    V2D out = schedule(roster, timeslots);

    verifySchedule(roster, out, slots);
}