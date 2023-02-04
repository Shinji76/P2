#include "Progetto/AbstractCard.h"

class Memory: public IEngine {
  private:
    std::vector<const Item::AbstractCard*> items;

  public:
    Memory();
    virtual ~Memory();
    virtual Memory& add(const Item::AbstractItem* item);
    virtual Memory& remove(const Item::AbstractItem* item);
    virtual Memory& clear();
    virtual ResultSet search(const Query& query) const;
};