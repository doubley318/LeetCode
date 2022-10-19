
            if (nums[i] > a)
            {
                c = b;
                b = a;
                a = nums[i];
            }
            else if (nums[i] > b)
            {
                c = b;
                b = nums[i];
            }
            else if (nums[i] > c)
            {
                c = nums[i];
            }