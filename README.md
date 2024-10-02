1)In this implementation, we've chosen to represent a linked list using the names of flowers instead of generic terms like "node". This decision enhances conceptual clarity. Since flower names are utilized as parameters, strings and pointers become pivotal. Employing call by reference simplifies function calls. We've explored various insertion scenarios, particularly addressing the challenge of inserting when the node name is unknown. To handle this, we search for the position using the name associated with the node variable, thereby introducing an additional case for insertion.
 2) The use of a doubly linked list to manage a list of audio effects in a real-time audio processing application. The key components of the code include:

EffectNode Structure: This struct defines a node in the doubly linked list, containing:

effectName: A string representing the name of the audio effect (e.g., "Reverb").
next: A pointer to the next effect in the list.
prev: A pointer to the previous effect in the list.
EffectList Class: This class manages the list of audio effects and provides functionality to:

Add an Effect: addEffect(const std::string& effectName) method adds a new audio effect to the end of the list.
Remove an Effect: removeEffect(const std::string& effectName) method removes a specific audio effect from the list based on its name.
Display Effects: displayEffects() method prints all the audio effects currently in the list.
Main Function: In the main() function:

An instance of EffectList is created.
Several audio effects are added to the list.
The effects are displayed.
An effect is removed from the list, and the updated list is displayed again.


