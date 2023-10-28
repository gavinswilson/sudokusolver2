# Function that calculates for given list of candiates what the binary representation is
# for example 9 options should be 0b111111111
def all_options_number_bin(self):
    return (2**self.options_max-1)
# account for mins

def get_mask_for_option(self, opt):
    return (2**(opt))