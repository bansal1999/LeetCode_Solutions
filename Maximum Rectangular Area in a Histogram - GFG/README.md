# Maximum Rectangular Area in a Histogram
## Medium 
<div class="problem-statement">
                <p><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank"></a></p><div style="margin: 14px 0px !important;" class="row"><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank">             <div class="col-md-12" style="cursor:pointer;background: #EFF8F3 0% 0% no-repeat padding-box; display: flex; align-items: center; position:                 relative; padding: 1.5%; border-radius: 10px; display: inline-block; text-align: center; font-weight: 600; color: #333"> <img src="https://media.geeksforgeeks.org/img-practice/gcs2022thumbnail-1649059370.png" alt="Lamp" width="46" height="40" style="background: transparent 0% 0% no-repeat padding-box;opacity: 1; margin: 0 16px;" class="img-responsive"> Geeks Summer Carnival is LIVE NOW &nbsp; <i class="fa fa-external-link" aria-hidden="true"></i> </div></a></div><p><span style="font-size:18px">Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is<strong> 1 unit</strong>, there will be <strong>N</strong> bars height of each bar will be given by the array <strong>arr</strong>.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 7
arr[] = {6,2,5,4,5,1,6</span><span style="font-size:18px">}
<strong>Output: </strong>12<strong>
Explanation: 
</strong></span><img alt="" src="http://d1hyf4ir1gqw6c.cloudfront.net/wp-content/uploads/histogram1.png" class="img-responsive"><span style="font-size:18px">
</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 8
arr[] = {7 2 8 9 1 3 6 5</span><span style="font-size:18px">}
<strong>Output: </strong>16<strong>
Explanation: </strong>Maximum size of the histogram 
will be 8&nbsp; and there will be 2 consecutive 
histogram. And hence the area of the 
histogram will be 8x2 = 16.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
The task is to complete the function&nbsp;<strong>getMaxArea</strong>() which takes the array arr[] and its size N as inputs and&nbsp;finds the largest rectangular area possible and <strong>returns</strong> the answer.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complxity</strong> : O(N)<br>
<strong>Expected Auxilliary Space</strong> : O(N)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>6</sup><br>
1 ≤ arr[i] ≤ 10<sup>12</sup></span></p>
 <p></p>
            </div>