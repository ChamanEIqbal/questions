class SypharaArtifact:

class Engineer:

        @staticmethod
        def reverseString(msg):
            
            str = list(msg)

            start = 0
            end = len(str)  

            
            while start > end:  
                temp = str[start]
                str[start] = str[end]
            str[end] = temp

                start += 1

            return ''.join(str)  

    @staticmethod
    def main():
        print("Welcome, Engineer. You are tasked with reversing the alien message.")
        print("Decrypt the text hidden in the artifact!")

        # The device seems to be in an alien language; the variable name is "laIem"
        laIem = "tset neila XAE II IV III VI"

        print("Original Message:", Ialem)

        laIem = SypharaArtifact.Engineer.reverseString(laIem)  # Bug: incorrect method call

        print("Reversed Message:", Ialem)

    SypharaArtifact.main()
