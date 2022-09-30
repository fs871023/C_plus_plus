void delete_recursively (RingNode*& current)
{
    if(current->next != NULL)//if the list is not end
    {
        RingNode* temp=current;//the node you want to delete
        current=current->next;//move forward, so we won't delete current, which cause us lost the nodes
        delete temp;//delete it
        delete_recursively(current);
    }
    else return;

}
